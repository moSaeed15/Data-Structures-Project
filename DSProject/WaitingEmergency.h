#pragma once
#include "Missions.h"
#include "LinkedQueue.h"


class WaitingEmergency :public Missions {
protected:
	int waitingDays = 0;

public:
	WaitingEmergency(int eventday, long int Targetlocation, int MissionDuration, int Significance, int ID)
		:Missions(eventday, Targetlocation, MissionDuration, Significance, ID)
	{
		R = nullptr;
	}

	bool assignEMRover(LinkedQueue<PolarRovers>& QPR, LinkedQueue<EmergencyRovers>& QER) {
		if (!QER.isEmpty()) {
			EmergencyRovers ER;

			if (QER.dequeue(ER)) {
				R = &ER;
				return true;
			}
		}
		else if (!QPR.isEmpty()) {
			PolarRovers PR;

			if (QPR.dequeue(PR)) {
				R = &PR;
				return true;
			}
		}
		return false;
	}

	void incrementEWaitingDays() {
		waitingDays++;
	}

	int getWaitingEDays() {
		return waitingDays;
	}

	WaitingEmergency():Missions()
	{
	}

	~WaitingEmergency() {

	}

}; 
