#ifndef _Mars_Station_
#define _Mars_Station_

#include <fstream>
#include "EmergencyRovers.h"
#include "PolarRovers.h"
#include "WaitingEmergency.h"
#include "WaitingPolar.h"
#include "InExecutionMission.h"
#include "UI.h"
#include "EventFormulation.h"


class MarsStation
{
private:
	int currentDay;
	int WD;
	int ExD;
	int CD;
	int NP, NE, SP, SE;
	int N; //number of missions the rover completes before performing a checkup
	int CP, CE; //checkup duration
	int E; //number of events
	char Event, TYP;
	int ED, ID, TLOC, MDUR, SIG;
	UI UI;
	LinkedQueue<PolarRovers> PolarRoverQ;
	LinkedQueue<EmergencyRovers> EmergencyRoverQ;
	LinkedQueue<EventFormulation> QEF;
	LinkedQueue<WaitingPolar> QPM;
	PriorityQueue<WaitingEmergency> PriQE;
	LinkedQueue<InExecution_Mission> Inex;
public:
	MarsStation()
	{
		currentDay = 0;
		NP = 0; NE = 0;
		SP = 0; SE = 0;
		N = 0; CP = 0; CE = 0;
		E = 0;
		Event = 'F'; TYP = '-'; ED = 0; ID = 0; TLOC = 0; MDUR = 0; SIG = 0;
	}

	void loadFile()
	{
		UI.input();
		ifstream inputFile(UI.getFilename(), ios::in);
		if (inputFile.is_open())
		{
			inputFile >> NP >> NE >> SP >> SE >> N >> CP >> CE >> E;

			//creating list of formulation events
			for (int i = 0; i < E; i++)
			{
				inputFile >> Event >> TYP >> ED >> ID >> TLOC >> MDUR >> SIG;
				EventFormulation EF(TYP, ED, TLOC, MDUR, SIG, ID);
				QEF.enqueue(EF);
			}

			//creating list of polar rovers
			for (int i = 0; i < NP; i++)
			{
				PolarRovers PR(CP, NP, SP);
				PolarRoverQ.enqueue(PR);
			}

			//creating list of emergency rovers
			for (int i = 0; i < NE; i++)
			{
				EmergencyRovers ER(CE, NE, SE);
				EmergencyRoverQ.enqueue(ER);
			}
		}
		else
		{
			cout << "Couldn't open file..." << endl;
		}
	}

	void ExecuteEvents()
	{
		LinkedQueue<EventFormulation> tempQ(QEF);
		while (!tempQ.isEmpty())
		{
			EventFormulation EF;
			tempQ.dequeue(EF);
			if (currentDay == EF.getEventDay()) {
				QEF.dequeue(EF);
				EF.Excute(QPM, PriQE);
			}
			else {
				QEF.dequeue(EF);
				QEF.enqueue(EF);
			}
		}
	}

	void AssignMissions()
	{
		while (!EmergencyRoverQ.isEmpty() || !PolarRoverQ.isEmpty())
		{
			WaitingEmergency EM;
			WaitingPolar PM;

			if (PriQE.dequeue(EM)) {
				EM.assignEMRover(PolarRoverQ, EmergencyRoverQ);
				InExecution_Mission inexcutionM(EM);
				Inex.enqueue(inexcutionM);
			}
			else if (QPM.dequeue(PM)) {
				PM.assignPMRover(PolarRoverQ);
				InExecution_Mission inexcutionM(PM);
				Inex.enqueue(inexcutionM);
			}
			else {
				break;
			}
		}
		EmergencyRoverQ.print();
		PolarRoverQ.print();
		Inex.print();
		QPM.print();
	}
	//TO DO:
	//Implement a function to move missions from waiting to in-execution to completed

	//TO DO:
	//Implement a function to move rovers from available to in-execution to checkup to available again
	void moveToCompleted() {








	}




	void Statistics() {
		//calculate statistics needed to create output file
	}

	void SaveFile()
	{
		//creates output file and calls UI.ouput
		ofstream out("output.txt", ios::out);
		out << "CD  ID  FD  WD  ED" << endl;

		//////////////  TO DO  /////////////
	}

	~MarsStation()
	{
	}
};

#endif