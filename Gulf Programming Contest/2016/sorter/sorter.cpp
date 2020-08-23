#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int sorter(string &S) {
	int pos = 0;
	string copy = S;
	for (int i = 0; i < S.size(); i++) {
		if(S[0] > S[i])
			pos++;
		else if(S[0] == S[i])
			if(S > copy)
				pos++;
		rotate(copy.begin(), copy.begin() + 1, copy.end());
	}
	return pos;
}

int main() {
	freopen("sorter.in", "r", stdin);
	freopen("output.out", "w", stdout);
	
	int N;
	cin >> N;
	cin.ignore();
	while (N--) {
		string S;
		getline(cin, S);
		cout << sorter(S) << endl;
	}
	
	return 0;
}