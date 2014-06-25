// C20StreamIt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// Iterators for istreams and ostreams
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	ifstream in("C20StreamIt.cpp");
	istream_iterator<string> init(in), end;
	ostream_iterator<string> out(cout, "\n");
	vector<string> vs;
	copy(init, end, back_inserter(vs));
	copy(vs.begin(), vs.end(), out);
	*out++ = vs[0];
	*out++ = "That's all, folks!";
	cin.get();
	return 0;
}

