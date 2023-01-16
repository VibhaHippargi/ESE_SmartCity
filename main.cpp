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

Vehicle v1;


static string function_response(int distance_of_ahead_vehicle, char accident_occur, char path_available, State current_state) {
	Accident_Scenario a1(distance_of_ahead_vehicle, accident_occur, path_available);
	State _state = a1.State_Changes(current_state);
	std::string response;
	while (_state != State::driving_normal)
	{
		if (_state == State::decelerating)
		{
			response = v1.update_speed(_state);
		}
		if (_state == State::changed_path)
		{
			response = v1.update_direction(_state, path_available);
		}
		if (_state == State::changed_lane_direction)
		{
			response = v1.update_lane(_state, 't');
		}
		return response;
		_state = a1.State_Changes(_state);
	}
	if (_state == State::driving_normal)
	{
		response = v1.drive_normal(_state);
	}
	return response;
}

int main()
{
	int distance_of_ahead_vehicle = 0;
	char accident_occur = 'f';
	char path_available = 'f';
	State current_state = State::driving_normal;
	Accident_Scenario a1(distance_of_ahead_vehicle, accident_occur, path_available);

	cout << "Press q to Quit, 't' for True and 'f' for False \n";
	while (true)
	{
		cout << "My distance from message transmitter: ";
		if (!(cin >> distance_of_ahead_vehicle))
		{
			cout << "Integer numbers only allowed";
			break;
		}
		cout << "Enter if Accident occured: ";
		cin >> accident_occur;
		if (accident_occur == 'q')
		{
			break;
		}
		cout << "Enter if Alternate path available: ";
		cin >> path_available;
		if (path_available == 'q')
		{
			break;
		}
		a1.setdistance_of_ahead_vehicle(distance_of_ahead_vehicle);
		a1.setalternate_path_available(path_available);
		a1.setaccident_occured(accident_occur);

	}
	string response = function_response(distance_of_ahead_vehicle, accident_occur, path_available, current_state);

	cout << response;
}