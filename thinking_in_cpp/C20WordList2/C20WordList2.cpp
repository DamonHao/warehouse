// C20WordList2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// Eliminating strtok() from Wordlist.cpp
#include <string>
#include <cstring>
#include <set>
#include <iostream>
#include <fstream>
#include <iterator>
using namespace std;

int main(int argc, char* argv[]) {
	using namespace std;
	ifstream in("test.txt");
	if(in == NULL)
		return 0;
	istreambuf_iterator<char> p(in), end;
	set<string> wordlist;
	while (p != end) {
		string word;
		//string is a container
		insert_iterator<string> 
			ii(word, word.begin());
		// Find the first alpha character:
		while(!isalpha(*p) && p != end)
			p++;
		// Copy until the first non-alpha character:
		while (isalpha(*p) && p != end){
			*(ii++) = *(p++);
		}
		if (word.size() != 0)
			wordlist.insert(word);
	} 
	// Output results:
	copy(wordlist.begin(), wordlist.end(),
		ostream_iterator<string>(cout, "\n"));
	cin.get();
} ///:~
