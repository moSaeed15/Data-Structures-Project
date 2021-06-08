#pragma once
#include "Rovers.h"



class CheckupEmergencyRover : public Rovers
{
public:
	CheckupEmergencyRover(int checkup, int nMissions, int speed)
	{
		CheckupDuration = checkup;
		NumberOfMissions = nMissions;
		this->speed = speed;
		AtCheckup = true;
	}
	CheckupEmergencyRover() :Rovers()
	{

	}

	CheckupEmergencyRover(InExecutionRovers EXR)
	{
		CheckupDuration = EXR.getCheckupDuration();
		NumberOfMissions = EXR.getNumberOfMissions();
		speed = EXR.getSpeed();
		AtCheckup = EXR.getAtCheckup();
		dateEnteredCheckup = EXR.getdateEnteredCheckup();
	}

	void SetisAtCheckup(bool x)
	{
		AtCheckup = x;
	}

	bool GetisAtCheckup()
	{
		return AtCheckup;
	}

	~CheckupEmergencyRover()
	{
	}
};