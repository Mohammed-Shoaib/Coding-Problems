/*
Problem Statement: https://www.hackerrank.com/challenges/30-generics/problem
*/

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void printArray(vector<T>& arr) {
	for (T& ele: arr)
		cout << ele << endl;
}