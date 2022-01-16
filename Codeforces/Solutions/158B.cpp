// Problem Code: 158B
 
#include <iostream>
#include <vector>

using namespace std;

int taxi(int n, vector<int>& s) {
	int cabs = 0, size = 4;
	vector<int> freq(size);
	
	for (int& x: s) {
		cabs += x / size;
		freq[x % size]++;
	}
	
	// combine one 3 and one 1
	cabs += freq[3];
	freq[1] = max(0, freq[1] - freq[3]);
	
	// combine two 2s
	cabs += (freq[2] + 1) / 2;
	
	// combine one 2 and two 1s
	if (freq[2] & 1)
		freq[1] = max(0, freq[1] - 2);
	
	// combine four 1s
	cabs += (freq[1] + 4 - 1) / 4;
	
	return cabs;
}

int main() {
	int n;
	cin >> n;
	vector<int> s(n);
	for (int i = 0; i < n; i++)
		cin >> s[i];
	cout << taxi(n, s);
	return 0;
}