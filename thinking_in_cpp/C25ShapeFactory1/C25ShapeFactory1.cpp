// C25ShapeFactory1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "purge.h"
#include <iostream>
#include <string>
#include <exception>
#include <vector>
using namespace std;

class Shape {
public:
	virtual void draw() = 0;
	virtual void erase() = 0;
	virtual ~Shape() {}
	class BadShapeCreation : public exception {
		string reason;
	public:
		BadShapeCreation(string type) {
			reason = "Cannot create type " + type;
		}
		const char *what() const { 
			return reason.c_str(); 
		}
	};
	static Shape* factory(string type) 
		throw(BadShapeCreation);
};

class Circle : public Shape {
	Circle() {} // Private constructor
	friend class Shape;
public:
	void draw() { cout << "Circle::draw\n"; }
	void erase() { cout << "Circle::erase\n"; }
	~Circle() { cout << "Circle::~Circle\n"; }
};

class Square : public Shape {
	Square() {}
	friend class Shape;
public:
	void draw() { cout << "Square::draw\n"; }
	void erase() { cout << "Square::erase\n"; }
	~Square() { cout << "Square::~Square\n"; }
};

Shape* Shape::factory(string type) 
	throw(Shape::BadShapeCreation) {
		if(type == "Circle") return new Circle();
		if(type == "Square") return new Square();
		throw BadShapeCreation(type);
}

char* shlist[] = { "Circle", "Square", "Square",
	"Circle", "Circle", "Circle", "Square", "" };

int main() {
	vector<Shape*> shapes;
	try {
		for(char** cp = shlist; **cp; cp++)
			shapes.push_back(Shape::factory(*cp));
	} catch(Shape::BadShapeCreation e) {
		cout << e.what() << endl;
		return 1;
	}
	for(int i = 0; i < shapes.size(); i++) {
		shapes[i]->draw();
		shapes[i]->erase();
	}
	purge(shapes);
	cin.get();
} ///:~