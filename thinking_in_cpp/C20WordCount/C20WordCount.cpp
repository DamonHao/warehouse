// C20WordCount.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//{L} StreamTokenizer
// Count occurrences of words using a map
#include "StreamTokenizer.h"
#include <string>
#include <map>
#include <iostream>
#include <fstream>
using namespace std;

class Count {
	int i;
public:
	Count() : i(0) {}
	void operator++(int) { i++; } // Post-increment  
	int& val() { return i; }
};

typedef map<string, Count> WordMap;
typedef WordMap::iterator WMIter;

int main(int argc, char* argv[]) {
	ifstream in("ReadMe.txt");
	if(in == NULL)
	   return 0;
	
	StreamTokenizer words(in);
	WordMap wordmap;
	string word;
	while((word = words.next()).size() != 0)
		wordmap[word]++;
	for(WMIter w = wordmap.begin(); 
		w != wordmap.end(); w++)
		cout << (*w).first << ": "
		<< (*w).second.val() << endl;
	cin.get();
} ///:~

