#ifndef _COMPLETED_MISSION
#define _COMPLETED_MISSION
#include <iostream>
#include "InExecutionMission.h"
using namespace std;

template <typename T>
class Completed_Mission : public InExecution_Mission<T>
{
private:
	int CD;
public:
	Completed_Mission(T MType) : MissionType(MType)
	{
		FD = 0;
		Target_Location = 0.0;
		Mission_Duration = 0;
		significance = 0;
		CD = 0;
	}

	~Completed_Mission() {

	}
};
#endif