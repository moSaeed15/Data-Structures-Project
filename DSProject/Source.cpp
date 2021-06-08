#include<iostream>
#include "MarsStation.h"
int main() {

	MarsStation MS;
	MS.loadFile();
   	while (true) {
		MS.ExecuteEvents();
		MS.AssignMissions();
		MS.IncrementWD();
	
		MS.moveToCompleted();
	}
	return 0;
}