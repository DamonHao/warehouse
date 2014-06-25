// C21PtrFun1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// Using ptr_fun() for single-argument functions
#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>
#include <iterator>
using namespace std;

char* n[] = { "01.23", "91.370", "56.661",
	"023.230", "19.959", "1.0", "3.14159" };
const int nsz = sizeof n / sizeof *n;

template<typename InputIter>
void print(InputIter first, InputIter last) {
	while(first != last)
		cout << *first++ << "\t";
	cout << endl;
}

int main() {
	print(n, n + nsz);
	vector<double> vd;
	transform(n, n + nsz, back_inserter(vd), atof);
	print(vd.begin(), vd.end());
	transform(n,n + nsz,vd.begin(), ptr_fun(atof));
	print(vd.begin(), vd.end());
	cin.get();
} ///:~
