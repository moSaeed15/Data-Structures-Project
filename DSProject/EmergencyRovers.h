#ifndef _EMERGENCY_ROVERS
#define _EMERGENCY_ROVERS
#include "Rovers.h"
#include <iostream>
using namespace std;


class EmergencyRovers : public Rovers
{
public:
	EmergencyRovers(int checkup, int nMissions, int speed)
	{
		CheckupDuration = checkup;
		NumberOfMissions = nMissions;
		this->speed = speed;
		AtCheckup = false;
	}
	EmergencyRovers():Rovers()
	{

	}



	void SetisAtCheckup(bool x)
	{
		AtCheckup = x;
	}

	bool GetisAtCheckup()
	{
		return AtCheckup;
	}

	~EmergencyRovers()
	{
	}
};
#endif

