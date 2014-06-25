// C20ListRobustness.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// lists are harder to break
#include <list>
#include <iostream>
using namespace std;
int main() {
	list<int> li(100, 0);
	list<int>::iterator i = li.begin();
	for(int j = 0; j < li.size() / 2; j++)
		i++;
	// Walk the iterator forward as you perform 
	// a lot of insertions
	for(int k = 0; k < 1000; k++)
		//there will be a error because it will 
		//point to some place out of the range of list
		li.insert(i++, k+1);  
	li.erase(i);
	//i++;
	//*i = 2; // Oops! It's invalid
	cout<<"Hello World~"<<endl;
	cin.get();
	return 0;
} ///:~
