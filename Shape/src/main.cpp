/*
 * main.cpp
 *
 *  Created on: Nov 21, 2019
 *      Author: kushal
 */

#include <string>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>

using namespace std;

class Shape{
protected:
	string name;

public:
	Shape(string n){
		name = n;
	}

	//virtual ~Shape() = 0;

	void setName(string n){
		name = n;
	}

	string getName() {
		return name;
	}

	// pure virtual function
	virtual double getArea() = 0;
};


class Circle : public Shape{
	double radius;

public:
	Circle(string name, double r) : Shape(name){
		radius = r;
	}

	//~Circle();

	void setRadius(double r){
		radius = r;
	}

	double getRadius(){
		return radius;
	}

	virtual double getArea(){
		return 3.1415*radius*radius;
	}
};


class Rectangle : public Shape{
protected:
	double base, width;

public:
	Rectangle(string n, double b, double w) : Shape(n){
		base = b;
		width = w;
	}

	//~Rectangle(){};

	void setBase(double b){
		base = b;
	}
	double getBase(){
		return base;
	}


	void setWidth(double w){
		width = w;
	}
	double getWidth(){
		return width;
	}
	virtual double getArea(){
		return base*width;
	}

};

class Triangle : public Shape{
protected:
	double base, width;

public:
	Triangle(string n, double b, double w) : Shape(n){
		base = b;
		width = w;
	}

	//~Triangle(){}
	virtual double getArea(){
		return 0.5*base*width;
	}
};

int main(int argc, char** argv){
	Circle* c = new Circle("circle", 3.6);
	cout << c->getName() << endl;
	cout << c->getRadius() << endl;

	Rectangle* r = new Rectangle("rect", 5, 10);
	cout << r->getName()<< endl;
	cout << r->getBase() << endl;
	cout << r->getWidth() << endl;
	r->setBase(10);
	r->setWidth(5);
	cout << r->getBase() << endl;
	cout << r->getWidth() << endl;


	Triangle* t = new Triangle("triangle", 3,4);

	Shape* shapes[3] = {c,r,t};

	for(int i = 0; i< 3; i++){
		cout << "Shape : " << shapes[i]->getName() << " Area : " << shapes[i]->getArea() << endl;
	}
}


