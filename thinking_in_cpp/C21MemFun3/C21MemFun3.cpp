// C21MemFun3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// Using mem_fun()
#include "NumStringGen.h"
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <functional>
#include <iterator>
using namespace std;

int main() {
	const int sz = 9;
	vector<string> vs(sz);
	// Fill it with random number strings:
	generate(vs.begin(), vs.end(), NumStringGen());
	copy(vs.begin(), vs.end(), 
		ostream_iterator<string>(cout, "\t"));
	cout << endl;
	const char* vcp[sz];
	transform(vs.begin(), vs.end(), vcp, 
		mem_fun_ref(&string::c_str));
	vector<double> vd;
	transform(vcp,vcp + sz,back_inserter(vd),
		std::atof);
	copy(vd.begin(), vd.end(), 
		ostream_iterator<double>(cout, "\t"));
	cout << endl;
	cin.get();
} ///:~
