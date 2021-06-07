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

	public:
	//InExecution_Mission(int eventday, long double TargetLocation, int MissionDuration, int Significance, int ID) :Missions(eventday, TargetLocation, MissionDuration, Significance, ID)
	//{
	//}
	InExecution_Mission() :Missions()
	{

	}

	InExecution_Mission(WaitingPolar WP)
	{
		FD = WP.GetFD();
		Target_Location = WP.GetTarget_Location();
		Mission_Duration = WP.GetMission_Duration();
		significance = WP.Getsignificance();
		MissionID = WP.GetMissionID();
		R = WP.GetRover();
		type = 'P';
	}
	InExecution_Mission(WaitingEmergency WE)
	{
		FD = WE.GetFD();
		Target_Location = WE.GetTarget_Location();
		Mission_Duration = WE.GetMission_Duration();
		significance = WE.Getsignificance();
		MissionID = WE.GetMissionID();
		R = WE.GetRover();
		type = 'E';
	}

	~InExecution_Mission() {

	}
};
#endif