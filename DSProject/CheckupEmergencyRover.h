#pragma once
#include "Rovers.h"
#include <iostream>
using namespace std;


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
	CheckupEmergencyRover() 
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

	~CheckupEmergencyRover()
	{
	}
};