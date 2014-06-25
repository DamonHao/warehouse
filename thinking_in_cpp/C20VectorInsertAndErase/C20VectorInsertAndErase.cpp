// C20VectorInsertAndErase.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// Erasing an element from a vector
#include "Noisy.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	vector<Noisy> v;
	v.reserve(20);
	cout << "11 spaces have been reserved" << endl;
	generate_n(back_inserter(v), 10, NoisyGen());
	ostream_iterator<Noisy> out(cout, " ");
	cout << endl;
	copy(v.begin(), v.end(), out);
	cout << "Inserting an element:" << endl;
	vector<Noisy>::iterator it = 
		v.begin() + v.size() / 2; // Middle
	v.insert(it, Noisy());
	cout << endl;
	copy(v.begin(), v.end(), out);
	cout << "\nErasing an element:" << endl;
	// Cannot use the previous value of it:
	it = v.begin() + v.size() / 2;
	v.erase(it);
	cout << endl;
	copy(v.begin(), v.end(), out);
	cout << endl;
	cin.get();
	return 0;
}

