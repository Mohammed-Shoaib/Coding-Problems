/*
Problem Statement: https://www.hackerrank.com/challenges/30-inheritance/problem
*/

#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

class Student : public Person{
private:
	vector<int> testScores;
public:
	Student(string firstName, string lastName, int id, vector<int> scores) 
		: Person(firstName, lastName, id), testScores(scores) {}

	char calculate() {
		char grade;
		double avg = accumulate(testScores.begin(), testScores.end(), 0.0) / testScores.size();
		if (avg >= 90)
			grade = 'O';
		else if (avg >= 80)
			grade = 'E';
		else if (avg >= 70)
			grade = 'A';
		else if (avg >= 55)
			grade = 'P';
		else if (avg >= 40)
			grade = 'D';
		else
			grade = 'T';
		return grade;
	}
};