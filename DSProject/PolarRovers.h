#ifndef _POLAR_ROVERS
#define _POLAR_ROVERS
#include "Rovers.h"
#include <iostream>
using namespace std;


class PolarRovers : public Rovers
{
public:
	PolarRovers(int checkup, int nMissions, int speed)
	{
		CheckupDuration = checkup;
		NumberOfMissions = nMissions;
		this->speed = speed;
		AtCheckup = false;
	}
	PolarRovers():Rovers()
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

	~PolarRovers()
	{
	}
};
#endif
