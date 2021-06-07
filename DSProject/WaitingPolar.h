#pragma once
#include "Missions.h"


class WaitingPolar :public Missions {
protected:
	int waitingDays = 0;

public:
	WaitingPolar(int eventday, long int Targetlocation, int MissionDuration, int Significance, int ID)
		:Missions(eventday, Targetlocation, MissionDuration, Significance, ID)
	{
		
	}
	WaitingPolar():Missions()
	{

	}

	bool assignPMRover(LinkedQueue<PolarRovers>& QPR) {
		if (!QPR.isEmpty()) {
			PolarRovers PR;

			if (QPR.dequeue(PR)) {
				R = &PR;
				return true;
			}
		}
		return false;
	}
	void incrementPWaitingDays() {
		waitingDays++;
	}
	int getWaitingPDays() {
		return waitingDays;
	}
	~WaitingPolar() {

	}
	
};