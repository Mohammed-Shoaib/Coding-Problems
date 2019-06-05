/*
Problem Code: https://www.hackerrank.com/challenges/sparse-arrays/problem
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> matchingStrings(vector<string> &strings, vector<string> &queries) {
	vector<int> freq;
	unordered_map<string, int> map;
	for (auto s: strings)
		map[s]++;
	for (auto q: queries)
		freq.push_back(map[q]);
	return freq;
}

int main() {
	int n, q;
	cin >> n;
	vector<string> strings(n);
	for (int i = 0; i < n; i++)
		cin >> strings[i];
	cin >> q;
	vector<string> queries(q);
	for (int i = 0; i < q; i++)
		cin >> queries[i];
	vector<int> freq = matchingStrings(strings, queries);
	for (int i = 0; i < freq.size(); i++)
		cout << freq[i] << endl;
    return 0;
}