#pragma once
#include <iostream>
#include "Event.h"
#include "WaitingEmergency.h"
#include "WaitingPolar.h"
#include"LinkedQueue.h"
#include "PriorityQueue.h"


class EventFormulation :public Event
{
private:
	char EventType;
	int EventDay;
	int ID;
	char MissionType;
	int TargetLocation;
	int MissionDuration; //no. of days needed at target location
	int Significance;
public:
	EventFormulation()
	{
		EventType = 'F';
		EventDay = 0;
		ID = 0;
		MissionType = '-';
		TargetLocation = 0;
		MissionDuration = 0;
		Significance = 0;
	}
	EventFormulation(char MTYP, int ED, int TLOC, int MDUR, int SIG, int ID)
	{
		EventType = 'F';
		EventDay = ED;
		this->ID = ID;
		MissionType = MTYP;
		TargetLocation = TLOC;
		MissionDuration = MDUR;
		Significance = SIG;
	}

	void Excute(LinkedQueue<WaitingPolar>& QPM, PriorityQueue<WaitingEmergency>& PriQE)
	{
		if (MissionType == 'E')
		{
			WaitingEmergency EM(EventDay, TargetLocation, MissionDuration, Significance, ID);

			//Higher periority is given to missins with higher significance and missions the has been first formulated
			//to mission with longer mission durations and farer target locations.
			//we assumed max event day is day 100.
			int missionWeight = (100 - EventDay) + Significance + TargetLocation + MissionDuration;

			PriQE.enqueue(EM, missionWeight);
		}
		else if (MissionType == 'P')
		{
			WaitingPolar PM(EventDay, TargetLocation, MissionDuration, Significance, ID);
			QPM.enqueue(PM);
		}


	}
	int getEventDay() {
		return EventDay;
	}
	~EventFormulation()
	{
	}


};