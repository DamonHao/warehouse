// C20Inserters.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// Different types of iterator inserters
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <iterator>
using namespace std;

int a[] = { 1, 3, 5, 7, 11, 13, 17, 19, 23 };

template<class Cont>
void frontInsertion(Cont& ci) {
	copy(a, a + sizeof(a)/sizeof(int), 
		front_inserter(ci));
	copy(ci.begin(), ci.end(),
		ostream_iterator<int>(cout, " "));
	cout << endl;
}

template<class Cont>
void backInsertion(Cont& ci) {
	copy(a, a + sizeof(a)/sizeof(int), 
		back_inserter(ci));
	copy(ci.begin(), ci.end(),
		ostream_iterator<int>(cout, " "));
	cout << endl;
}

template<class Cont>
void midInsertion(Cont& ci) {
	typename Cont::iterator it = ci.begin();
	//it++; it++; it++; equal to below statement
	advance(it,3);
	copy(a, a + sizeof(a)/(sizeof(int) * 2),
		inserter(ci, it));
	copy(ci.begin(), ci.end(),
		ostream_iterator<int>(cout, " "));
	cout << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	deque<int> di;
	list<int>  li;
	vector<int> vi;
	// Can't use a front_inserter() with vector
	frontInsertion(di);
	frontInsertion(li);
	di.clear();
	li.clear();
	backInsertion(vi);
	backInsertion(di);
	backInsertion(li);
	midInsertion(vi);
	midInsertion(di);
	midInsertion(li);
	cin.get();
	return 0;
}

