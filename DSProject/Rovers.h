#ifndef _ROVERS
#define _ROVERS
#include <iostream>
using namespace std;

//base class of Rovers
class Rovers
{
protected:
	int CheckupDuration;
	int NumberOfMissions;
	int speed;
	bool AtCheckup;
	//static int RoverID = 0;
public:
	Rovers()
	{
		//RoverID++;
		CheckupDuration = 0;
		NumberOfMissions = 0;
		speed = 0;
		AtCheckup = false;
	}

	virtual void SetisAtCheckup(bool x) = 0;
	virtual bool GetisAtCheckup() = 0;
	void incrementNoMission() {
		NumberOfMissions++;
	}
	int getCheckupDuration() {
		return CheckupDuration;
	}

	int getNumberOfMissions() {

		return NumberOfMissions;
	}

	int getSpeed() {

		return speed;
	}

	bool getAtCheckup() {
		return AtCheckup;
		}
	~Rovers()
	{
	}
};
#endif
