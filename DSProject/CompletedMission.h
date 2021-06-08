#ifndef _COMPLETED_MISSION
#define _COMPLETED_MISSION
#include <iostream>
#include "InExecutionMission.h"
using namespace std;

class CompletedMission : public InExecution_Mission
{
private:

public:
	CompletedMission() :InExecution_Mission()
	{

	}
	CompletedMission(InExecution_Mission IM)
	{
		FD = IM.GetFD();
		CD = IM.GetFD() + IM.GetED() + IM.GetWD();
		waitingDays = IM.GetWD();
		ED = IM.GetED();
		Target_Location = IM.GetTarget_Location();
		Mission_Duration = IM.GetMission_Duration();
		significance = IM.Getsignificance();
		MissionID = IM.GetMissionID();
		R = IM.GetRover();
		if (IM.getType() == 'P') {
			type = 'P';
		}
		else {
			type = 'E';
		}
	}
	~CompletedMission() {

	}
};
#endif