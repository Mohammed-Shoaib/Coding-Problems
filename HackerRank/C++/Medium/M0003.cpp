/*
Problem Statement: https://www.hackerrank.com/challenges/virtual-functions/problem
*/

#include <array>
#include <string>
#include <numeric>

class Person {
protected:
	int age;
	string name;
public:
	virtual void getdata() = 0;
	virtual void putdata() = 0;
};

class Professor : public Person {
private:
	int publications, cur_id;
	static int id;
public:
	Professor() : cur_id(++id) {}

	void getdata() override {
		cin >> name >> age >> publications;
	}

	void putdata() override {
		cout << name << " " << age << " " << publications << " " << cur_id << endl;
	}
};

class Student : public Person {
private:
	int cur_id;
	static int id;
	array<int, 6> marks;
public:
	Student() : cur_id(++id) {}

	void getdata() override {
		cin >> name >> age;
		for (int i = 0; i < marks.size(); i++)
			cin >> marks[i];
	}

	void putdata() override {
		int sum = accumulate(marks.begin(), marks.end(), 0);
		cout << name << " " << age << " " << sum << " " << cur_id << endl;
	}
};

int Professor::id = 0;
int Student::id = 0;