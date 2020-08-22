/*
Problem Statement: https://www.hackerrank.com/challenges/30-operators/problem
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double mealCost;
	int tipPercent, taxPercent;

	cin >> mealCost >> tipPercent >> taxPercent;
	mealCost += mealCost * (tipPercent + taxPercent) / 100;
	cout << round(mealCost);

	return 0;
}