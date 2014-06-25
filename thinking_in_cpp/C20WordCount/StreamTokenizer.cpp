#include "stdafx.h"
#include "StreamTokenizer.h"
using namespace std;

string StreamTokenizer::next() {
	string result;
	if(p != end) {
		insert_iterator<string>
			ii(result, result.begin());
		while(p != end && isDelimiter(*p))
			p++;
		while (p != end && !isDelimiter(*p))
			*ii++ = *p++;
	}
	return result;
} ///:~
