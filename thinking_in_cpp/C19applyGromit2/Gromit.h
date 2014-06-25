#ifndef GROMIT_H
#define GROMIT_H
#include <iostream>
class Gromit{ 
  int arf;
public:
  Gromit(int arf = 1) : arf(arf + 1) {}
  
  void speak(int) {
    for(int i = 0; i < arf; i++)
      std::cout << "arf! ";
    std::cout << std::endl;
  }

  char eat(float) {
    std::cout << "chomp!" << std::endl;
    return 'z';
  }  int sleep(char, double) {
    std::cout << "zzz..." << std::endl;
    return 0;
  }

  void sit(void) {}
};
#endif