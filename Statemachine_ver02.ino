/**
 *
 *
 *  Arduino Code for Traffic Management State
 *
 *
 **/

#define GREEN_LED 	3
#define RED_LED 	4
#define YELLOW_LED 	5
#define BLUE_LED 	6

#define ACCIDENT_OCCURRED_BTN			10
#define ALTERNATIVE_PATH_AVAILABLE_BTN	11

// int A = 10;
// int B = 20;
int accidentOccurred, alternativePath;

enum State
{
	DRIVING_NORMAL,
	DECELERATING,
	CHANGE_PATH,
	CHANGE_LANE,
};

State currentState = DRIVING_NORMAL;

// accident occured and alternate path available
// changed lane direction state, when there is no alternate path available
// add led for fourth state


long readUltrasonicDistance(int triggerPin, int echoPin)
{
	pinMode(triggerPin, OUTPUT);  // Clear the trigger
	digitalWrite(triggerPin, LOW);
	delayMicroseconds(2);
	// Sets the trigger pin to HIGH state for 10 microseconds
	digitalWrite(triggerPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(triggerPin, LOW);
	pinMode(echoPin, INPUT);
	// Reads the echo pin, and returns the sound wave travel time in microseconds
	return pulseIn(echoPin, HIGH);
}

void setup()
{   
	Serial.begin(9600);
	Serial.println("Serial Monitor Started");
	pinMode(GREEN_LED, OUTPUT);
	pinMode(RED_LED, OUTPUT);
	pinMode(YELLOW_LED, OUTPUT);
	pinMode(BLUE_LED, OUTPUT);
	pinMode(ACCIDENT_OCCURRED_BTN, INPUT);
	pinMode(ALTERNATIVE_PATH_AVAILABLE_BTN, INPUT);

}

void loop()
{ 
	switch(currentState)
	{
		case DRIVING_NORMAL:
			digitalWrite(RED_LED, LOW);
			digitalWrite(YELLOW_LED, LOW);
			digitalWrite(BLUE_LED, LOW);
			//digitalWrite(8, LOW); //G LOW
			digitalWrite(GREEN_LED, HIGH); 
			//digitalWrite(2, HIGH); //R
			//digitalWrite(3,LOW);

			Serial.println("DRIVING NORMAL");
			accidentOccurred = digitalRead(ACCIDENT_OCCURRED_BTN);
			alternativePath = digitalRead(ALTERNATIVE_PATH_AVAILABLE_BTN);
			if (0.01723 * readUltrasonicDistance(9, 9) < 50)
			{
				currentState = DECELERATING;
			}
			else if (accidentOccurred == 1)
			{
				currentState = CHANGE_PATH;
			}
			else if (alternativePath == 1)
			{
				currentState = CHANGE_LANE;
			}
			delay(2000);
			break;

		case DECELERATING: 
			digitalWrite(GREEN_LED, LOW);
			digitalWrite(YELLOW_LED, LOW);
			digitalWrite(BLUE_LED, LOW);
			// digitalWrite(2, LOW); // R LOW
			digitalWrite(RED_LED, HIGH);
			// digitalWrite(6, HIGH); //B
			Serial.println("DECELERATING");
			currentState = CHANGE_PATH;
			delay(2000);
			break;

		case CHANGE_PATH: 
			digitalWrite(GREEN_LED, LOW);
			digitalWrite(RED_LED, LOW);
			digitalWrite(BLUE_LED, LOW);
			// digitalWrite(6, LOW); //B LOW
			digitalWrite(YELLOW_LED, HIGH);
			// digitalWrite(8, HIGH); //G
			Serial.println("CHANGING PATH");
			currentState = DRIVING_NORMAL;
			delay(2000);
			break;

		case CHANGE_LANE:
			digitalWrite(GREEN_LED, LOW);
			digitalWrite(RED_LED, LOW);
			digitalWrite(YELLOW_LED, LOW);
			digitalWrite(BLUE_LED, HIGH);
			break;

		default: 
			digitalWrite(YELLOW_LED, LOW);
			digitalWrite(GREEN_LED, LOW);
			digitalWrite(RED_LED, LOW);
			digitalWrite(BLUE_LED, LOW);
			break;
	}

	delay(1000);  
}