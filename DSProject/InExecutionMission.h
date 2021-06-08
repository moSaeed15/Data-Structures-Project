#ifndef _INEXECUTION_MISSION
#define _INEXECUTION_MISSION
#include <iostream>
#include "Missions.h"
#include "WaitingEmergency.h"
#include "WaitingPolar.h"
using namespace std;

class InExecution_Mission :public Missions
{
protected:
	char type;
	PolarRovers PR;
	EmergencyRovers ER;
	long int finishTime;
	int ED;
	public:
	//InExecution_Mission(int eventday, long double TargetLocation, int MissionDuration, int Significance, int ID) :Missions(eventday, TargetLocation, MissionDuration, Significance, ID)
	//{
	//}
	InExecution_Mission() :Missions()
	{
		finishTime = 0;
		type = '-';
	}

	InExecution_Mission(WaitingPolar WP, LinkedQueue<PolarRovers>& QPR)
	{
		FD = WP.GetFD();
		Target_Location = WP.GetTarget_Location();
		Mission_Duration = WP.GetMission_Duration();
		significance = WP.Getsignificance();
		MissionID = WP.GetMissionID();
		waitingDays = WP.GetWD();
		ED = 0;
	
		if (!QPR.isEmpty()) {
			PolarRovers tempPR;
			if (QPR.dequeue(tempPR)) {
				PR = tempPR;
				GetFinishTime();
				PR.setdateEnteredCheckup(finishTime);
			}
		}
		finishTime = GetFinishTime();
		type = 'P';
	}
	InExecution_Mission(WaitingEmergency WE, LinkedQueue<PolarRovers>& QPR, LinkedQueue<EmergencyRovers>& QER)
	{
		FD = WE.GetFD();
		Target_Location = WE.GetTarget_Location();
		Mission_Duration = WE.GetMission_Duration();
		significance = WE.Getsignificance();
		MissionID = WE.GetMissionID();
		waitingDays = WE.GetWD();
		ED = 0;

		if (!QER.isEmpty()) {
			EmergencyRovers tempER;

			if (QER.dequeue(tempER)) {
				ER = tempER;
				GetFinishTime();
				ER.setdateEnteredCheckup(finishTime);
			}
		}
		else if (!QPR.isEmpty()) {
			PolarRovers tempPR;
			if (QPR.dequeue(tempPR)) {
				PR = tempPR;
				GetFinishTime();
				PR.setdateEnteredCheckup(finishTime);
			}
		}
		finishTime = GetFinishTime();
		type = 'E';
	}

	void incrementED() {
		ED++;
	}
	char getType() {
		return type;
	}
	PolarRovers getPR() {
		return PR;
	}

	EmergencyRovers getER() {
		return ER;
	}
	int GetFinishTime() {

		if (type == 'P') {
			finishTime = ((Target_Location / PR.getSpeed()) / 25) * 2 + Mission_Duration;
		}
		else {
			if (PR.getSpeed() != 0) {
				finishTime = ((Target_Location / PR.getSpeed()) / 25) * 2 + Mission_Duration;
			}
			else {
				finishTime = ((Target_Location / ER.getSpeed()) / 25) * 2 + Mission_Duration;
			}
		}

		return finishTime;
	}
	
	bool isFinished(int currentDay) {

		if (FD + finishTime == currentDay) {
			return true;
		}
		else {
			return false;
		}




	}
	~InExecution_Mission() {

	}
};
#endif