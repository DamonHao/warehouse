// C20TokenizeTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// Test StreamTokenizer
#include "StreamTokenizer.h"
#include <iostream>
#include <fstream>
#include <set>
using namespace std;

int main(int argc, char* argv[]) {
  ifstream in("test.txt");
  if(in == NULL){
	  return 0;
  }
  if(in == NULL){return 0;}
  StreamTokenizer words(in);
  set<string> wordlist;
  string word;
  while((word = words.next()).size() != 0)
    wordlist.insert(word);
  // Output results:
  copy(wordlist.begin(), wordlist.end(),
    ostream_iterator<string>(cout, "\n"));
  cin.get();
} ///:~

