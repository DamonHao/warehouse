// C21PtrFun2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// Using ptr_fun() for two-argument functions
#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>
#include <cmath>
#include <iterator>
using namespace std;

double d[] = { 01.23, 91.370, 56.661,
	023.230, 19.959, 1.0, 3.14159 };
const int dsz = sizeof d / sizeof *d;

int main() {
	vector<double> vd;
	// bind2nd() must have a function object as 
	//its first argument and a pointer to function
	//won't cut it;
	transform(d, d + dsz, back_inserter(vd), 
		bind2nd(ptr_fun<double,double>(pow), 2.0));
	//the below statement will cause compile error 
	//no overloaded function ptr_fun match
	//bind2nd(ptr_fun(pow), 2.0) 
	copy(vd.begin(), vd.end(),
		ostream_iterator<double>(cout, " "));
	cout << endl;    
	cin.get();
} ///:~

