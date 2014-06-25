// C20DequeCoreDump.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// How to break a program using a deque
#include <queue>
#include <iostream>
#include <iterator>
using namespace std;

int main() {
	deque<int> di(100, 0);
	// No problem iterating from beginning to end,
	// even though it spans multiple blocks:
	copy(di.begin(), di.end(), 
		ostream_iterator<int>(cout, " "));
	deque<int>::iterator i = // In the middle:
		di.begin() + di.size() / 2;;
	// Walk the iterator forward as you perform 
	// a lot of insertions in the middle:

	for(int j = 0; j < 1000; j++) {
		cout << j << endl;
		di.insert(i++, 1); // Eventually breaks
	}
	cin.get();
} ///:~