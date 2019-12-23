/*
Problem Statement: https://www.hackerrank.com/challenges/30-class-vs-instance/problem
*/

#include <iostream>

using namespace std;

class Person {
public:
    int age;
    
    Person(int initialAge) {
        if (initialAge < 0) {
            cout << "Age is not valid, setting age to 0." << endl;
            age = 0;
        }
        else
            age = initialAge;
    }
    void amIOld() {
        if (age < 13)
            cout << "You are young." << endl;
        else if (age < 18)
            cout << "You are a teenager." << endl;
        else
            cout << "You are old." << endl;
    }
    void yearPasses() {
        age++;
    }
};