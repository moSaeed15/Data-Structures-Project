#include<iostream>
#include "MarsStation.h"
int main() {

	MarsStation MS;
	MS.loadFile();
   	while (MS.getnumberOfCompletedMissions()!=MS.getnumberOfEvents()) {
		MS.Simulate();
	}
	MS.SaveFile();
	MS.Statistics();
	return 0;
}