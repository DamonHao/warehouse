// C19Sorted.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// Testing template specialization
#include "Sorted.h"
#include "Urand.h"
#include "C:\Users\damon\Documents\Visual Studio 2012\Projects\C19ArraySize\C19ArraySize\arraySize.h"
#include <iostream>
#include <string>
using namespace std;
 "is", "running", "big", "dog", "a",
};
char* words2[] = { 
int _tmain(int argc, _TCHAR* argv[])
{
 // the instantiation will find the most matchable 
 //template funtion becatuse template specialization

  Sorted<int> is;
  Urand<47> rand;
  for(int i = 0; i < 15; i++)
    is.push_back(rand());
  for(int l = 0; l < is.size(); l++)
    cout << is[l] << ' ';
  cout << endl;
  is.sort();
  for(int l = 0; l < is.size(); l++)
    cout << is[l] << ' ';
  cout << endl;

  // Uses the template partial specialization:
  Sorted<string*> ss;
  for(int i = 0; i < asz(words); i++)
    ss.push_back(new string(words[i]));
  for(int i = 0; i < ss.size(); i++)
    cout << *ss[i] << ' ';
  cout << endl;
  ss.sort();
  for(int i = 0; i < ss.size(); i++)
    cout << *ss[i] << ' ';
  cout << endl;

  // Uses the full char* specialization:
  Sorted<char*> scp;
  for(int i = 0; i < asz(words2); i++)
  for(int i = 0; i < scp.size(); i++)
    cout << scp[i] << ' ';
  cout << endl;
  scp.sort();
  for(int i = 0; i < scp.size(); i++)
    cout << scp[i] << ' ';
  cout << endl;
	cin.get();
	return 0;
}
