#include<iostream>
#include "MarsStation.h"
int main() {

	MarsStation MS;
	MS.loadFile();

		MS.ExecuteEvents();
		MS.AssignMissions();
	
	return 0;
}