// Different ways to fill sequences
#ifndef GENERATORS_H
#define GENERATORS_H
#include <set>
#include <cstdlib>
#include <cstring>
#include <ctime>

// A generator that can skip over numbers:
class SkipGen {
	int i;
	int skp;
public:
	SkipGen(int start = 0, int skip = 1)
		: i(start), skp(skip) {}
	int operator()() {
		int r = i;
		i += skp;
		return r;
	}
};

// Generate unique random numbers from 0 to mod:
class URandGen {
	std::set<int> used;
	int modulus;
public:
	URandGen(int mod) : modulus(mod) { 
		std::srand(std::time(0)); 
	}
	int operator()() {
		while(true) {
			int i = (int)std::rand() % modulus;
			if(used.find(i) == used.end()) {
				used.insert(i);
				return i;
			}
		}
	}
};

// Produces random characters:
class CharGen {
	static const char* source;
	static const int len;
public:
	CharGen() { std::srand(std::time(0)); }
	char operator()() { 
		return source[std::rand() % len];
	}
};

// Statics created here for convenience, but
// will cause problems if multiply included:
const char* CharGen::source = "ABCDEFGHIJK"
	"LMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
const int CharGen::len = std::strlen(source);
#endif // GENERATORS_H ///:~