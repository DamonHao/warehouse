// C21FindBlanks.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// Demonstrate mem_fun_ref() with string::empty()
#include <algorithm>
#include <list>
#include <string>
#include <fstream>
#include <functional>
#include <iterator>
#include <iostream>
using namespace std;

typedef list<string>::iterator LSI;

LSI blank(LSI begin, LSI end) {
	return find_if(begin, end, 
		mem_fun_ref(&string::empty));
}

int main(int argc, char* argv[]) {
	string fileName = "ReadMe.txt";
	ifstream in(fileName);
	if(in == NULL)
		return 0;
	list<string> ls;
	string s;
	while(getline(in, s))
		ls.push_back(s);
	LSI lsi = blank(ls.begin(), ls.end());
	while(lsi != ls.end()) {
		*lsi = "A BLANK LINE";
		lsi = blank(lsi, ls.end());
	}
	string f("HaHa.txt");
	//f += ".out";
	ofstream out(f.c_str());
	copy(ls.begin(), ls.end(), 
		ostream_iterator<string>(out, "\n"));
	cin.get();
} ///:~