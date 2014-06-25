// C20Reversible.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// Using reversible containers
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

	ifstream in("C20Reversible.cpp");
	string line;
	vector<string> lines;
	while(getline(in, line))
		lines.push_back(line);
	vector<string>::reverse_iterator r;
	for(r = lines.rbegin(); r != lines.rend(); r++)
		cout << *r << endl;
	cin.get();
	return 0;
}

