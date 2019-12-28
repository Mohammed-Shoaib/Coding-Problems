/*
Problem Statement: https://www.hackerrank.com/challenges/30-scope/problem
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Difference {
private:
	vector<int> elements;
public:
	int maximumDifference;

	Difference(vector<int> elements) : elements(elements) {}

	void computeDifference() {
		int min_ele, max_ele;
		min_ele = *min_element(elements.begin(), elements.end());
		max_ele = *max_element(elements.begin(), elements.end());
		maximumDifference = max_ele - min_ele;
	}
};