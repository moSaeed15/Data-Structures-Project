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
#include "InExecutionRovers.h"
#include "CompletedMission.h"
class MarsStation
{
private:
	int currentDay;
	/*int WD;
	int ExD;
	int CD;*/
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
	LinkedQueue<WaitingPolar> polarMQ;
	PriorityQueue<WaitingEmergency> EmergencyMQ;
	PriorityQueue<InExecutionRovers> InExR;
	LinkedQueue<InExecution_Mission> Inex;
	LinkedQueue<CompletedMission> CompletedMQ;
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
				EF.Excute(polarMQ, EmergencyMQ);
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

			if (EmergencyMQ.dequeue(EM)) {
				EM.assignEMRover(PolarRoverQ, EmergencyRoverQ);
				InExecution_Mission inexcutionM(EM, PolarRoverQ, EmergencyRoverQ);
				Inex.enqueue(inexcutionM);
			if(	inexcutionM.getPR().getSpeed() != 0){
				inexcutionM.getPR().incrementNoMission();
				InExecutionRovers InExecutionR(inexcutionM.getPR());
			
				InExR.enqueue(InExecutionR, inexcutionM.GetFinishTime());
			}
			else {
				inexcutionM.getER().incrementNoMission();
				InExecutionRovers InExecutionR(inexcutionM.getER());
				InExR.enqueue(InExecutionR, inexcutionM.GetFinishTime());
			}
			}
			else if (polarMQ.dequeue(PM)) {
				PM.assignPMRover(PolarRoverQ);
				InExecution_Mission inexcutionM(PM, PolarRoverQ);
				Inex.enqueue(inexcutionM);
				inexcutionM.getPR().incrementNoMission();
				InExecutionRovers InExecutionR(inexcutionM.getPR());
				InExR.enqueue(InExecutionR, inexcutionM.GetFinishTime());
			}
			else {
				return;
			}
		}
	}
	//TO DO:
	//Implement a function to move missions from waiting to in-execution to completed
	void IncrementWD() {
		if (polarMQ.isEmpty() && EmergencyMQ.isEmpty()) {
			return;
		}
		WaitingEmergency EM;
		WaitingPolar PM;
		int countP=PolarRoverQ.count();
		int countE=EmergencyMQ.count();
		for (int i = 0; i < countE;i++) {
			EmergencyMQ.dequeue(EM);
			EM.incrementEWaitingDays();
			int missionWeight = (100 - EM.GetFD()) + EM.Getsignificance() + EM.GetTarget_Location() + EM.GetMission_Duration();
			EmergencyMQ.enqueue(EM, missionWeight);
		}
		for (int i = 0; i < countE; i++) {
			polarMQ.dequeue(PM);
			PM.incrementPWaitingDays();
			polarMQ.enqueue(PM);
		}

	}
	//void IncrementED() {
	//	if (Inex.isEmpty()) {
	//		return;
	//	}
	//	InExecution_Mission InExecM;
	//	int countInExeuction = Inex.count();
	//	for (int i = 0; i < countInExeuction; i++) {
	//		Inex.dequeue(InExecM);
	//		if (!InExecM.isFinished(currentDay));
	//		InExecM.incrementED();
	//		Inex.enqueue(InExecM);

	//	}
	//}
	//TO DO:
	//Implement a function to move rovers from available to in-execution to checkup to available again
	void moveToCompleted() {
		InExecution_Mission InExecM;
		int countInExeuction = Inex.count();
		
		for (int i = 0; i < countInExeuction; i++) {
			Inex.dequeue(InExecM);
			if (InExecM.isFinished(currentDay)) {
				CompletedMission CM(InExecM);
				CompletedMQ.enqueue(CM);
			}
			else {
				InExecM.incrementED();
				Inex.enqueue(InExecM);
			}
		}





	}


	void moveRovers() {

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