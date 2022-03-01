// Problem Code: 69A
 
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string young_physicist(vector<vector<int>>& forces) {
	for (int j = 0; j < forces[0].size(); j++) {
		int sum = 0;
		
		for (int i = 0; i < forces.size(); i++)
			sum += forces[i][j];
		
		if (sum != 0)
			return "NO";
	}
	
	return "YES";
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> forces(n, vector<int>(3));
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < forces[i].size(); j++)
			cin >> forces[i][j];
	
	cout << young_physicist(forces);
	
	return 0;
}