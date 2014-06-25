// C20WordList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// Display a list of words used in a document
#include <string>
#include <cstring>
#include <set>
#include <iostream>
#include <fstream>
using namespace std;
const char* delimiters =
	" \t;()\"<>:{}[]+-=&*#.,/\\~";

int main(int argc, char* argv[]) {
	ifstream in("test.txt");
	set<string> wordlist;
	string line;
	while(getline(in, line)) {
		// Capture individual words:
		//strtok_s
		char* s = // Cast probably won't crash:
			strtok((char*)line.c_str(), delimiters);
		while(s) {
			// Automatic type conversion:
			wordlist.insert(s); 
			s = strtok(0, delimiters);
		}
	}
	// Output results:
	copy(wordlist.begin(), wordlist.end(),
		ostream_iterator<string>(cout, "\n"));
	cin.get();
} ///:~
