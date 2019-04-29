/*
Problem Statement: https://www.hackerrank.com/challenges/c-tutorial-class/problem
*/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Student {
private:
    int age, standard;
    string first_name, last_name;
public:
    Student(int age, string first_name, string last_name, int standard) {
        this->age = age;
        this->first_name = first_name;
        this->last_name = last_name;
        this->standard = standard;
    }

    int get_age() {
        return age;
    }

    void set_age(int age) {
        this->age = age;
    }

    string get_first_name() {
        return first_name;
    }

    void set_first_name(string first_name) {
        this->first_name = first_name;
    }

    string get_last_name() {
        return last_name;
    }

    void set_last_name(string last_name) {
        this->last_name = last_name;
    }

    int get_standard() {
        return standard;
    }

    void set_standard(int standard) {
        this->standard = standard;
    }

    string to_string() {
        ostringstream ss;
        ss << age << ',' << first_name << ',' << last_name << ',' << standard;
        return ss.str();
    }
};

int main() {
    int age, standard;
    string first_name, last_name;
    cin >> age >> first_name >> last_name >> standard;
    Student S(age, first_name, last_name, standard);
    cout << S.get_age() << endl;
    cout << S.get_last_name() << ", " << S.get_first_name() << endl;
    cout << S.get_standard() << endl;
    cout << endl;
    cout << S.to_string() << endl;
    return 0;
}