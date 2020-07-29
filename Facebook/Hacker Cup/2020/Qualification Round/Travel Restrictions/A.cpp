/*
Problem Statement: https://www.facebook.com/codingcompetitions/hacker-cup/2020/qualification-round/problems/A
Time: O(n²)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

#include <iostream>
#include <string>

using namespace std;

void travel_restrictions(int N, string& I, string& O) {
	// go through each flight
	for (int i = 0; i < N; i++) {
		string flight(N, 'N');
		flight[i] = 'Y';

		for (int j = i + 1; j < N; j++) {
			if (O[j - 1] == 'N' || I[j] == 'N')
				break;
			flight[j] = 'Y';
		}

		for (int j = i - 1; j >= 0; j--) {
			if (O[j + 1] == 'N' || I[j] == 'N')
				break;
			flight[j] = 'Y';
		}
		
		cout << flight << endl;
	}
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int N;
		string I, O;
		cin >> N >> I >> O;
		cout << "Case #" << x << ": " << endl;
		travel_restrictions(N, I, O);
	}
	return 0;
}