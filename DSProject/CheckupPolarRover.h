#pragma once
#include "Rovers.h"



class CheckupPolarRover : public Rovers
{
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