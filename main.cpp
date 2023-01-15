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

int main()
{
	int distance_of_ahead_vehicle = 0;
	char accident_occur = 'f';
	char path_available = 'f';

	State current_state = State::driving_normal;
	Accident_Scenario a1(distance_of_ahead_vehicle, accident_occur, path_available);
	Vehicle v1;
	cout << "Press q to Quit, 't' for True and 'f' for False \n";
	while (true)
	{
		cout << "Enter distance from next vehicle: ";
		if (!(cin >> distance_of_ahead_vehicle))
		{
			cout << "Integer numbers only allowed";
			break;
		}
		cout << "Enter Accident possiblility: ";
		cin >> accident_occur;
		if (accident_occur == 'q')
		{
			break;
		}
		cout << "Enter if path available: ";
		cin >> path_available;
		if (path_available == 'q')
		{
			break;
		}
		a1.setdistance_of_ahead_vehicle(distance_of_ahead_vehicle);
		a1.setalternate_path_available(path_available);
		a1.setaccident_occured(accident_occur);

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
			cout << response;
			_state = a1.State_Changes(_state);
		}
		if (_state == State::driving_normal)
		{
			v1.drive_normal(_state);
		}
		cout << response;
	}
}