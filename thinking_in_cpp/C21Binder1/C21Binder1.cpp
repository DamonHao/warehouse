// C21Binder1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// Using STL "binders"
#include "Generators.h"
//#include "copy_if.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>
#include <iterator>

using namespace std;

int main() {
	const int sz = 10;
	const int max = 40;
	vector<int> a(sz), r;
	URandGen urg(max);
	ostream_iterator<int> out(cout, " ");
	generate_n(a.begin(), sz, urg);
	copy(a.begin(), a.end(), out);
	//the below way has error by converting 
	// vector<int>::iterator into int*
	/*int* d = find_if(a.begin(), a.end(), 
		bind2nd(less<int>(), 20));*/
	vector<int>::iterator d = find_if(a.begin(), a.end(), 
		bind2nd(less<int>(), 20));
	cout << "\n *d = " << *d << endl;
	// copy_if() is not in the Standard C++ library
	// but is defined later in the chapter:
	copy_if(a.begin(), a.end(), back_inserter(r),
		bind2nd(less<int>(), 20));
	copy(r.begin(), r.end(), out);
	cout << endl;
	cin.get();
} ///:~