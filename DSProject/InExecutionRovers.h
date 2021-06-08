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
		type = '-';
	}
	InExecutionRovers() :Rovers()
	{
		type = '-';
	}
	char getType() {





		return type;
	}
	InExecutionRovers(PolarRovers PR)
	{
		CheckupDuration = PR.getCheckupDuration();
		NumberOfMissions = PR.getNumberOfMissions();
		speed = PR.getSpeed();
		AtCheckup = PR.getAtCheckup();
		type = 'P';
		dateEnteredCheckup = PR.getdateEnteredCheckup();
	}
	InExecutionRovers(EmergencyRovers ER)
	{
		CheckupDuration = ER.getCheckupDuration();
		NumberOfMissions = ER.getNumberOfMissions();
		speed = ER.getSpeed();
		AtCheckup = ER.getAtCheckup();
		type = 'E';
		dateEnteredCheckup = ER.getdateEnteredCheckup();
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