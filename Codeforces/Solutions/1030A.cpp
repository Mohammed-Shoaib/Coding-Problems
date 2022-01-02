// Problem Code: 1030A
 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string in_search_of_an_easy_problem(int n, vector<int>& p) {
	return find(p.begin(), p.end(), 1) == p.end() ? "EASY" : "HARD";
}

int main() {
	int n;
	cin >> n;
	vector<int> p(n);
	for (int i = 0; i < n; i++)
		cin >> p[i];
	cout << in_search_of_an_easy_problem(n, p);
	return 0;
}