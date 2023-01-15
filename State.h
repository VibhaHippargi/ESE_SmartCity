#ifndef State_h
#define State_h



	enum class State
	{
		driving_normal = 1,
		decelerating,
		changed_path,
		changed_lane_direction
	};
	class Vehicle
	{
	public:
		Vehicle();
		std::string update_speed(State current);
		std::string drive_normal(State current);
		std::string update_direction(State current, char direction_avail);
		std::string update_lane(State current, char lane_avail);
	};
	class Accident_Scenario
	{
	public:

		int distance_of_ahead_vehicle;
		char accident_occured;
		char alternate_path_available;
		Accident_Scenario();
		Accident_Scenario(int distance_of_ahead_vehicle, char accident_occured, char alternate_path_available);
		void setdistance_of_ahead_vehicle(int dist);
		int getdistance_of_ahead_vehicle();
		void setaccident_occured(char alt);
		char getaccident_occured();
		void setalternate_path_available(char alt);
		char getalternate_path_available();
		State State_Changes(State current);
	};

	
	extern Vehicle veh;
	extern Accident_Scenario acc;

#endif // !State_h