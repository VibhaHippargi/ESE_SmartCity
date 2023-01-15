
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <dos.h>
#include <windows.h>
#include <complex>
#include <chrono>
#include<string.h>
#include "State.h"


using namespace std;



Vehicle::Vehicle() {

}



string Vehicle::update_speed(State current)
{
	if (current == State::decelerating)
	{
		return ("Acknowledgement: Vehicle decelerating\n");
	}
	else
	{
		return("State and Request mis-match");
	}
}

string Vehicle::drive_normal(State current)
{
	if (current == State::driving_normal)
	{
		return ("Acknowledgement: Vehicle continue same path\n");
		
	}
	else
	{
		return("State and Request mis-match");
	}
}

string Vehicle::update_direction(State current, char direction_avail)
{
	if (direction_avail == 't') {
		return  ("Acknowledgement: Vehicle Changed Path\n");
		
	}
	else
	{
		return("State and Request mis-match");
	}
}

string Vehicle::update_lane(State current, char lane_avail)
{
	if (lane_avail == 't') {
		return ("Acknowledgement: Vehicle Changed Lane Direction\n");
		
	}
	else
	{
		return("State and Request mis-match");
	}
}


	Accident_Scenario:: Accident_Scenario()
	{
		this->distance_of_ahead_vehicle = 0;
		this->alternate_path_available = 'f';
		this->accident_occured = 'f';
	}

	Accident_Scenario::Accident_Scenario(int dist, char accident, char path) {
		this->distance_of_ahead_vehicle = dist;
		this->accident_occured = accident;
		this->alternate_path_available = path;
	}
	 void Accident_Scenario::setdistance_of_ahead_vehicle(int dist)
	{
		this->distance_of_ahead_vehicle = dist;
	}
	int Accident_Scenario::getdistance_of_ahead_vehicle()
	{
		return(this->distance_of_ahead_vehicle);
	}
	void Accident_Scenario::setaccident_occured(char alt)
	{
		this->accident_occured = alt;
	}
	char Accident_Scenario::getaccident_occured()
	{
		return(this->accident_occured);
	}
	void Accident_Scenario::setalternate_path_available(char alt)
	{
		this->alternate_path_available = alt;
	}
	char Accident_Scenario::getalternate_path_available()
	{
		return(this->alternate_path_available);
	}
	
 State Accident_Scenario::State_Changes(State current){
	 Vehicle v1;
	switch (current) {
		
	case State::driving_normal:		

		
		if ((accident_occured == 't') && (distance_of_ahead_vehicle <= 50))
		{
			current = State::decelerating;
			cout << "Message: Vehicle decelerate" << endl;		
		}
		else
		{
			cout << "Message: Vehicle drive normal" << endl;
		}
		return (current);
		break;

	case State::decelerating:
		
		Sleep(5000);
		if (alternate_path_available == 't')
		{
			current = State::changed_path;
			cout << "Message: Vehicle change path" << endl;
		}
		else
		{
			current = State::changed_lane_direction;
			cout << "Message: Vehicle change lane direction" << endl;
		}
		return (current);
		break;

	case State::changed_path:
		
		Sleep(5000);
		current = State::driving_normal;
		cout << "Message: Vehicle drive normal" << endl;
		
		return (current);
		break;

	case State::changed_lane_direction:
		
		Sleep(5000);
		current = State::driving_normal;
		cout << "Message: Vehicle drive normal" << endl;
		
		return (current);
		break;

	default:
		
		break;
	}

	}
	  




