/*
Problem Statement: https://www.hackerrank.com/challenges/30-testing/problem
*/

#include <iostream>
#include <vector>

using namespace std;

class TestDataEmptyArray {
public:
	static vector<int> get_array() {
		return {};
	}
};

class TestDataUniqueValues {
public:
	static vector<int> get_array() {
		return {3, 1, 2};
	}

	static int get_expected_result() {
		return 1;
	}
};

class TestDataExactlyTwoDifferentMinimums {
public:
	static vector<int> get_array() {
		return {4, 3, 0, 1, 0, 5};
	}

	static int get_expected_result() {
		return 2;
	}
};