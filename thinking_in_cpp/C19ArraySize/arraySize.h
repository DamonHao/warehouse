// Use template induction to discover the size of array
#ifndef ARRAYSIZE_H
#define ARRAYSIZE_H
template<typename T, int size>
int asz(T (&)[size]){ return size;}
#endif