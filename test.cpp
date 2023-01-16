#include "pch.h"
#include "C:\ESE\Sem1\ESE\Testing\ESE_State_machine\State.h"
#include<string.h>
#include <iostream>
using namespace std;

TEST(Negative_Vehicle_input, State_Test) {
	Accident_Scenario a1(20,'t','t');
	Vehicle v1;
	std::string str1= v1.drive_normal(State::changed_lane_direction);
	std::string str2 = "State and Request mis-match";
	EXPECT_EQ(str1,str2);
    EXPECT_TRUE(true);
}

TEST(Negative_distance, State_Test) {
	Accident_Scenario a1(-20, 't', 't');
	int i1 = a1.getdistance_of_ahead_vehicle();
	EXPECT_EQ(0,i1);
	EXPECT_TRUE(true);
}
TEST(Negative_accident_input, State_Test) {
	Accident_Scenario a1(20, 'y', 't');	
	char i1 = a1.getaccident_occured();
	EXPECT_EQ('f', i1);
	EXPECT_TRUE(true);
}
TEST(Negative_path_input, State_Test) {
	Accident_Scenario a1(20, 't', 'y');
	char i1 = a1.getalternate_path_available();
	EXPECT_EQ('f', i1);
	EXPECT_TRUE(true);
}

TEST(Negative_Distance_greater, State_Test) {
	Accident_Scenario a1(60, 't', 't');
	State  str1 = a1.State_Changes(State::driving_normal); 
	EXPECT_EQ(State::driving_normal, str1); 
	EXPECT_TRUE(true); 
}
