// Problem Code: 116A
 
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int tram(vector<pair<int, int>>& stops) {
	int max_capacity, capacity;
	max_capacity = capacity = 0;
	
	for (pair<int, int>& stop: stops) {
		capacity -= stop.first;
		capacity += stop.second;
		max_capacity = max(capacity, max_capacity);
	}
	
	return max_capacity;
}

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> stops(n);
	
	for (pair<int, int>& stop: stops)
		cin >> stop.first >> stop.second;
	
	cout << tram(stops);
	
	return 0;
}