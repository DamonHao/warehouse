// FEditTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// Test the FileEditor tool
#include "FileEditor.h"
#include <sstream>
using namespace std;

int _tmain(int argc, char* argv[])
{
	FileEditor file("damon.txt");
	// Do something to the lines...
	int i = 1;
	FileEditor::iterator w = file.begin();
	while(w != file.end()) {
		ostringstream ss;
		ss << i++;
		*w = ss.str() + ": " + *w;
		w++;
	}
	// Now send them to cout:
	file.write();

	cin.get();
	return 0;
}

