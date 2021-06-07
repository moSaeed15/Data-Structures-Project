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


public:
	Missions(int eventday, long int TargetLocation, int MissionDuration, int Significance, int ID)
	{

		FD = eventday;
		Target_Location = TargetLocation;
		Mission_Duration = MissionDuration;
		significance = Significance;
		MissionID = ID;
		R = nullptr;
	}
	Missions()
	{
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