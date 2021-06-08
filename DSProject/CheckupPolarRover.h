#pragma once
#include "Rovers.h"



class CheckupPolarRover : public Rovers
{
private:



public:
	CheckupPolarRover(int checkup, int nMissions, int speed)
	{
		CheckupDuration = checkup;
		NumberOfMissions = nMissions;
		this->speed = speed;
		AtCheckup = true;

	}
	CheckupPolarRover() :Rovers()
	{
	}

	CheckupPolarRover(InExecutionRovers EXR)
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

	~CheckupPolarRover()
	{
	}
};