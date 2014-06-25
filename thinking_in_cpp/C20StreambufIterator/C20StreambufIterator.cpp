// C20StreambufIterator.cpp : Defines the entry point for the console application.
//
// istreambuf_iterator & ostreambuf_iterator
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream in("C20StreambufIterator.cpp");
	// Exact representation of stream:
	istreambuf_iterator<char> isb(in), end;
	ostreambuf_iterator<char> osb(cout);
	while(isb != end)
		*osb++ = *isb++; // Copy 'in' to cout
	cout << endl;
	ifstream in2("C20StreambufIterator.cpp");
	// Strips white space:
	istream_iterator<char> is(in2), end2;
	ostream_iterator<char> os(cout);
	while(is != end2)
		*os++ = *is++;
	cout << endl;
	cin.get();
	return 0;
}

