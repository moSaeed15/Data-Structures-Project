#pragma once
#include "Rovers.h"
#include "PolarRovers.h"
#include "EmergencyRovers.h"

class InExecutionRovers : public Rovers
{
	char type;

public:
	InExecutionRovers(int checkup, int nMissions, int speed)
	{
		CheckupDuration = checkup;
		NumberOfMissions = nMissions;
		this->speed = speed;
		AtCheckup = false;
	}
	InExecutionRovers() :Rovers()
	{

	}

	InExecutionRovers(PolarRovers PR)
	{
		CheckupDuration = ;
		NumberOfMissions = nMissions;
		this->speed = speed;
		AtCheckup = false;
		type = 'P';
	}
	InExecutionRovers(EmergencyRovers ER)
	{
		CheckupDuration = checkup;
		NumberOfMissions = nMissions;
		this->speed = speed;
		AtCheckup = false;
		type = 'E';
	}



	void SetisAtCheckup(bool x)
	{
		AtCheckup = x;
	}

	bool GetisAtCheckup()
	{
		return AtCheckup;
	}

	~InExecutionRovers()
	{
	}
};