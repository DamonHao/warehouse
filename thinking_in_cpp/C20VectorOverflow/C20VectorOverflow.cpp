// C20VectorOverflow.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// Shows the copy-construction and destruction
// That occurs when a vector must reallocate
// (It maintains a linear array of elements)
#include "Noisy.h"
//#include "../require.h"
#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>
#include <deque>
using namespace std;

int main(int argc, char* argv[]) {
	//requireArgs(argc, 1);
	int size = 1000;
	// if(argc >= 2) size = atoi(argv[1]);
	 vector<Noisy> vn;
	//deque<Noisy> vn;
	Noisy n;
	for(int i = 0; i < size; i++)
		vn.push_back(n);
	cout << "\n cleaning up \n";
	cin.get();
	return 0;
} ///:~

