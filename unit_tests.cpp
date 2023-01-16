#include <iostream>
#include "gtest/gtest.h"
#include "../ESE_State_machine/State.h"

using namespace std;

TEST(Alternative_path_not_available, State_test) {
    Accident_Scenario a1(10, 't', 'f');
    Vehicle v1;
    State  str1 = a1.State_Changes(State::decelerating);
    EXPECT_EQ(State::changed_lane_direction, str1);
    EXPECT_TRUE(true);
}

TEST(Alternative_path_available, State_test) {
    Accident_Scenario a1(10, 't', 't');
    Vehicle v1;
    State  str1 = a1.State_Changes(State::decelerating);
    EXPECT_EQ(State::changed_path, str1);
    EXPECT_TRUE(true);
}

TEST(Vehicle_changed_lane, Vehicle_response_test) {
    Accident_Scenario a1(10, 't', 'f');
    Vehicle v1;
    std::string response = v1.update_lane(State::driving_normal, 't');
    EXPECT_EQ(response, "Acknowledgement: Vehicle Changed Lane Direction\n");
    EXPECT_TRUE(true);
}

TEST(Vehicle_drive_normal, Vehicle_response_test) {
    Accident_Scenario a1(20, 't', 't');
    Vehicle v1;
    std::string response = v1.drive_normal(State::driving_normal);
    EXPECT_EQ(response, "Acknowledgement: Vehicle drive normal\n");
    EXPECT_TRUE(true);
}

TEST(Vehicle_changed_path, Vehicle_response_test) {
    Accident_Scenario a1(10, 't', 't');
    Vehicle v1;
    std::string response = v1.update_direction(State::driving_normal, 't');
    EXPECT_EQ(response, "Acknowledgement: Vehicle Changed Path\n");
    EXPECT_TRUE(true);
}