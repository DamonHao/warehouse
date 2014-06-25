// TemplateTemplate.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

// As long as things are simple, 
// this approach works fine:
template<typename C>
void print1(C& c) {
 //typename can be omited here
 typename C::iterator it;
  for(it = c.begin(); it != c.end(); it++)
    cout << *it << " ";
  cout << endl;
}

//this function can not pass compile
// error infor: begin is not a member of c
// Template-template argument must 
 //be a class; cannot use typename:
template<typename T,template<typename> class C>
void print2(C<T> & c){
    copy(c.begin(), c.end(), 
    ostream_iterator<T>(cout, " "));
    cout << endl;
}

void print3(vector<string> & c){
	vector<string>::iterator it ;
	for(it = c.begin();it != c.end(); it++)
		cout<<*it<<" ";
	cout<<endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<string> v(5, "Yow!");
	print1(v);
	print2(v);
	print3(v);
	cin.get();
	return 0;
}

