#ifndef _MISSIONS
#define _MISSIONS
#include <iostream>
#include"Rovers.h"
using namespace std;
//base class of Missions



class Missions
{
protected:
	int FD;
	long int Target_Location;
	int Mission_Duration;
	int significance;
	int MissionID;
	Rovers* R;
	int waitingDays;
	int ED;
	int CD;


public:
	Missions(int eventday, long int TargetLocation, int MissionDuration, int Significance, int ID)
	{
		waitingDays = 0;
		ED = 0;
		CD = 0;
		FD = eventday;
		Target_Location = TargetLocation;
		Mission_Duration = MissionDuration;
		significance = Significance;
		MissionID = ID;
		R = nullptr;
	}
	Missions()
	{
		waitingDays = 0;
		ED = 0;
		CD = 0;
		FD = 0;
		Target_Location = 0;
		Mission_Duration = 0;
		significance = 0;
		R = nullptr;
		MissionID = 0;
	}
	int GetFD() {
		return FD;
	}

	int GetWD() {
		return FD;
	}
	int GetED() {
		return ED;
	}
	int GetCD() {
		return CD;
	}
	long int GetTarget_Location() {
		return Target_Location;
	}

	int GetMission_Duration() {
		return Mission_Duration;
	}

	int Getsignificance() {
		return significance;
	}

	Rovers* GetRover() {

		return R;
	}

	int GetMissionID() {
		return MissionID;
	}


	~Missions()
	{
	}
};
#endif