// Program values can be changed by command line
#ifndef PROGVALS_H
#define PROGVALS_H
#include <map>
#include <iostream>
#include <string>

class ProgVals 
	: public std::map<std::string, std::string> {
public:
	ProgVals(std::string defaults[][2], int sz);
	void parse(int argc, char* argv[],
		std::string usage, int offset = 1);
	void print(std::ostream& out = std::cout);
};
#endif // PROGVALS_H ///:~