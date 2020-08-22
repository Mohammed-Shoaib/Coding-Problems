/*
Problem Statement: https://www.hackerrank.com/challenges/multi-level-inheritance-cpp/problem
*/

#include <iostream>

using namespace std;

class Triangle {
public:
	void triangle() {
		cout << "I am a triangle" << endl;
	}
};

class Isosceles : public Triangle {
public:
	void isosceles() {
		cout << "I am an isosceles triangle" << endl;
	}
};

class Equilateral : public Isosceles {
public:
	void equilateral() {
		cout << "I am an equilateral triangle" << endl;
	}
};

int main() {
	Equilateral eqr;
	eqr.equilateral();
	eqr.isosceles();
	eqr.triangle();
	return 0;
}