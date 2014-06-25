// C19applyGromit2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Gromit.h"
#include "applyMember.h"
#include <vector>
#include <iostream>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
  //this can not pass compile!!!
  SequenceWithApply<Gromit, vector> dogs;
  for(int i = 0; i < 5; i++)
    dogs.push_back(new Gromit(i));
  dogs.apply(&Gromit::speak, 1);
  dogs.apply(&Gromit::eat, 2.0f);
  dogs.apply(&Gromit::sleep, 'z', 3.0);
  dogs.apply(&Gromit::sit);
  cin.get();
  return 0;
}

