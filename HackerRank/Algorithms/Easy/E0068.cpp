/*
Problem Statement: https://www.hackerrank.com/challenges/missing-numbers/problem
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> missingNumbers(vector<int> arr, vector<int> brr) {
	vector<int> numbers;
	unordered_map<int, int> map;
	for(int i=0 ; i<brr.size() ; i++)
		map[brr[i]]++;
	for(int i=0 ; i<arr.size() ; i++)
		map[arr[i]]--;
	for(unordered_map<int, int>::iterator it=map.begin() ; it != map.end() ; it++)
		if(it->second)
			numbers.push_back(it->first);
	sort(numbers.begin(), numbers.end());
	return numbers;
}

int main()
{
	int n, m, num;
	vector<int> arr, brr, results;
	cin >> n;
	for(int i=0 ; i<n ; i++) {
		cin >> num;
		arr.push_back(num);
	}
	cin >> m;
	for(int i=0 ; i<m ; i++) {
		cin >> num;
		brr.push_back(num);
	}
	results = missingNumbers(arr, brr);
	for(int i=0 ; i<results.size() ; i++)
		cout << results[i] << " ";
	cout << endl;
	return 0;
}