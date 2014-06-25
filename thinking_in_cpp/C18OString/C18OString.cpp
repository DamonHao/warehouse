// C18OString.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <strstream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	const int sz = 100;
	cout << "type an int, a float and a string:";
	int i;
	float f;
	cin >> i >> f;
	cin >> ws; // Throw away white space
	char buf[sz];
	cin.getline(buf, sz); // Get rest of the line
	// (cin.rdbuf() would be awkward)

	//char buf[sz] = "xixi haha";
	ostrstream os(buf, sz, ios::app);
	os << endl;
	os << "integer = " << i << endl;
	os << "float = " << f << endl;
	os << ends;
	cout << buf;
	cout << os.rdbuf(); // Same effect, but it will 
	//cout << os.rdbuf(); // NOT the same effect

	//char buf[12];
	//cout<<buf;
	//char a=65;      
	//char *aptr=&a;
	//cout<<a<<endl;
	//cout<<* aptr<<endl;
	//cout<<aptr<<endl;
	cin.get();
	return 0;
}

