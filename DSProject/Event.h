#ifndef _EVENT
#define _EVENT
#include <iostream>
#include "WaitingEmergency.h"
#include "WaitingPolar.h"
using namespace std;

class Event
{
private:
	char EventType;
	int EventDay;
	int ID;
	char MissionType;
	long double TargetLocation;
	int MissionDuration; //no. of days needed at target location
	int Significance;

public:
	Event() {
		EventType = 'F';
		EventDay = 0;
		ID = 0;
		MissionType = 'P';
		TargetLocation = 0;
		MissionDuration = 0;
		Significance = 0;
	}

	virtual void Excute() {

	}


	~Event() {

	}
};
#endif
