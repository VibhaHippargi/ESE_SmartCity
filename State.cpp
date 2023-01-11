#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <time.h>
#include <dos.h>
#include <windows.h>
#include <complex>
#include <chrono>
#include <thread>
using namespace std;


int main()

{
	enum class State
	{
		driving_normal=1,
		decelerating,
		changed_path,
		changed_lane_direction
	};

	
	int distance_of_ahead_vehicle;
	
	char accident_occured,alternate_path_available;
	State previous_state = State::driving_normal;
	//State current_state = State::decelerating;
	State current_state= previous_state;
	
	for (int i = 0; i <=2; i++)
	{
		//cout << "iteration: "<<i << endl;

		switch (current_state) {

		case State::driving_normal:
			cout << "please give details" << endl;
			cout << "distance_ahead in int value, Accident_occured type t or f ,Alternate path available type t or f" << endl;
			cin >> distance_of_ahead_vehicle;
			cin >> accident_occured;
			cin >> alternate_path_available;

			//cout << "current State is driving normal"<<endl;
			if ((accident_occured == 't') && (distance_of_ahead_vehicle <= 20))
			{
				current_state = State::decelerating;
				cout << "current State is decelerating"<<endl;
				//cout << State::decelerating << endl;
			}
			else
			{
				cout << "current State is driving normal" << endl;
			}

			break;

		case State::decelerating:
			//cout << "current_state is decelerating" << endl;
			Sleep(5000);
			if (alternate_path_available == 't')
			{
				current_state = State::changed_path;
				cout << "current_state is changed path" << endl;
			}
			else
			{
				current_state = State::changed_lane_direction;
				cout << "current_state is changed lane direction" << endl;
			}
			break;

		case State::changed_path:
			//cout << "current_state is changed path" << endl;
			Sleep(5000);
			current_state = State::driving_normal;
			cout << "current State is driving normal" << endl;
			cout << "ONE COMPLETE FLOW DONE" << endl;
			break;

		case State::changed_lane_direction:
			//cout << "current_state is changed lane direction" << endl;
			Sleep(5000);
			current_state = State::driving_normal;
			cout << "current State is driving normal" << endl;
			cout << "ONE COMPLETE FLOW DONE" << endl;
			break;


		default:
			break;
		}

		previous_state = current_state;
	}
}
