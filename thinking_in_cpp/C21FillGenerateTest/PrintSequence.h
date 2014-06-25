// Prints the contents of any sequence
#ifndef PRINTSEQUENCE_H
#define PRINTSEQUENCE_H
#include <iostream>

//template<typename InputIter>
//void print(InputIter first, InputIter last,
//	char* nm = "", char* sep = "\n", 
//	std::ostream& os = std::cout) { 
//		if(*nm != '\0') // Only if you provide a string
//			os << nm << ": " << sep; // is this printed
//		while(first != last)
//			os << *first++ << sep;
//		os << std::endl;
//}

// Use template-templates to allow type deduction
// of the typename T:
template<typename T, template<typename> class C>
void print(C<T>& c, char* nm = "", 
	char* sep = "\n", 
	std::ostream& os = std::cout) {
		if(*nm != '\0') // Only if you provide a string
			os << nm << ": " << sep; // is this printed
		std::copy(c.begin(), c.end(), 
			std::ostream_iterator<T>(os, " "));
		cout << endl;
}
#endif // PRINTSEQUENCE_H ///:~