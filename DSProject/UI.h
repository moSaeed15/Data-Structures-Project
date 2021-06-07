#ifndef _UI_
#define _UI_
#include <iostream>
#include <string.h>
using namespace std;

class UI
{
private:
	string filename;
	int Mode;
public:
	UI();
	string getFilename();
	void input();
	void output();
	~UI();
};
UI::UI()
{
	Mode = 0;
}

string UI::getFilename()
{
	return filename;
}

void UI::input()
{
	cout << "Enter file name: ";
	string x;
	cin >> x;
	filename = x;
	int y = 0;

	cout << "1. Interactive Mode " << endl << "2. Step-By-Step Mode " << endl << "3. Silent Mode" << endl;
	cout << "Select Simulation Mode (1,2 or 3): ";
	cin >> y;
	Mode = y;

	output();
}

void UI::output()
{
	if (Mode == 1)
	{

	}
	else if (Mode == 2)
	{

	}
	else if (Mode == 3)
	{
		cout << "Silent Mode" << endl;
		cout << "Simulation Starts..." << endl;
		cout << "Simulation ends, Output file created" << endl;
	}
}
UI::~UI()
{
}

#endif

