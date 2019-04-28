/*
Problem Statement: https://www.hackerrank.com/challenges/c-tutorial-struct/problem
*/

#include <iostream>

using namespace std;

struct Student {
    int age, standard;
    string first_name, last_name;
    void print();
};

void Student::print() {
    cout << age << " " << first_name << " " << last_name << " " << standard << endl;
}

int main() {
    Student S;
    cin >> S.age >> S.first_name >> S.last_name >> S.standard;
    S.print();
    return 0;
}