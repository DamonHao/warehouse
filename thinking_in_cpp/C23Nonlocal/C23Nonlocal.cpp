// C23Nonlocal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// setjmp() & longjmp()
#include <iostream>
#include <csetjmp>
using namespace std;

class Rainbow {
public:
	Rainbow() { cout << "Rainbow()" << endl; }
	~Rainbow() { cout << "~Rainbow()" << endl; }
};

jmp_buf kansas;

void oz() {
	Rainbow rb;
	for(int i = 0; i < 3; i++)
		cout << "there's no place like home\n";
	//goto the state stored in kansas
	longjmp(kansas, 47);
}

int main() {
	//store proessor state into kansas for longjmp() 
	if(setjmp(kansas) == 0) {
		cout << "tornado, witch, munchkins...\n";
		oz();
	} else {
		cout << "Auntie Em! "
			<< "I had the strangest dream..."
			<< endl;
	}
	cin.get();
} ///:~
