// C19applyGromit.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Gromit.h"
#include "applySequence.h"
#include <vector>
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
  vector<Gromit*> dogs;
  for(int i = 0; i < 5; i++)
   dogs.push_back(new Gromit(i));
  apply(dogs, &Gromit::speak, 1);
  apply(dogs, &Gromit::eat, 2.0f);
  apply(dogs, &Gromit::sleep, 'z', 3.0);
  apply(dogs, &Gromit::sit);
	cin.get();
	return 0;
}

