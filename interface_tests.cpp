#include <iostream>
#include "gtest/gtest.h"
#include "../ESE_State_machine/State.h"
#include "../ESE_State_machine/main.cpp"

using namespace std;

TEST(Vehicle_decelerate, Interface_tests) {
    string expected_response = function_response(10, 't', 't', State::driving_normal);
    string actual_response = "Acknowledgement: Vehicle decelerating\n";
    EXPECT_EQ(expected_response, actual_response);
    EXPECT_TRUE(true);
}

TEST(Vehicle_drive_normal, Interface_tests) {
    string expected_response = function_response(10, 't', 'f', State::changed_lane_direction);
    string actual_response = "Acknowledgement: Vehicle drive normal\n";
    EXPECT_EQ(expected_response, actual_response);
    EXPECT_TRUE(true);
}

TEST(Vehicle_change_path, Interface_tests) {
    string expected_response = function_response(10, 't', 't', State::decelerating);
    string actual_response = "Acknowledgement: Vehicle Changed Path\n";
    EXPECT_EQ(expected_response, actual_response);
    EXPECT_TRUE(true);
}