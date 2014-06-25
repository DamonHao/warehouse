// C21MemFun1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// Applying pointers to member functions
#include "purge.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>
using namespace std;

class Shape {
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class Circle : public Shape {
public:
	virtual void draw() {
		cout << "Circle::Draw()" << endl;
	}
	~Circle() {
		cout << "Circle::~Circle()" << endl;
	}
};

class Square : public Shape {
public:
	virtual void draw() {
		cout << "Square::Draw()" << endl;
	}
	~Square() {
		cout << "Square::~Square()" << endl;
	}
};

int main() {
	vector<Shape*> vs;
	vs.push_back(new Circle);
	vs.push_back(new Square);
	for_each(vs.begin(), vs.end(), 
		mem_fun(&Shape::draw));
	purge(vs);
	cin.get();
} ///:~
