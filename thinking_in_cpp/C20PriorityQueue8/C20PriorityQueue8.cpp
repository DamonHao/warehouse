// C20PriorityQueue8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// A more compact version of PriorityQueue7.cpp
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iterator>
using namespace std;

template<class T>
class PQV : public priority_queue<T> {
public:
	typedef vector<T> TVec;
	// the potential problem is that vector function return
	//vector<T> by value, which may cause some overhead issues
	// with complex vlues of parameter type T
	TVec vector() {
		TVec r(c.begin(), c.end());
		// c is already a heap
		sort_heap(r.begin(), r.end(), comp);
		// Put it into priority-queue order:
		reverse(r.begin(), r.end());
		return r;
	}
};

int main() {
	PQV<int> pqi;
	srand(time(0));
	for(int i = 0; i < 100; i++)
		pqi.push(rand() % 25);
	const vector<int>& v = pqi.vector();
	copy(v.begin(), v.end(),
		ostream_iterator<int>(cout, " "));
	cout << "\n-----------\n"; 
	while(!pqi.empty()) {
		cout << pqi.top() << ' ';
		pqi.pop();
	}
	cin.get();
} ///:~
