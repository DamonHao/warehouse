// C19ArraySize.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

// this function can get the size of array
template<typename T, int size>
int asz(T (&)[size]){ return size;}

int getArraySize(int a[]);

int _tmain(int argc, _TCHAR* argv[])
{
	int a[12],b[20];
	cout<<asz(a)<<endl;
	cout<<asz(b)<<endl;
	cout<<sizeof(a)<<endl;
	//this function would't get resutl you want 
	//because once you pass an array to any function,it becomes pointers type
	//and so sizeof(a) would give the size of pointer,not array;
	cout<<getArraySize(a)<<endl;
	cin.get();
	return 0;
}
int getArraySize(int a[]){
	return sizeof(a)/sizeof(a[0]);
}

