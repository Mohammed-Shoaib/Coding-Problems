// Problem Code: LOSTMAX

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int maximumValue(vector<int> &A) {
	int mx = 0;
	bool flag = false;
	for (int i = 0; i < A.size(); i++) {
		if (!flag && A[i] == A.size() - 1)
			flag = true;
		else
			mx = max(A[i], mx);
	}
	return mx;
}

int main() {
	int T;
	cin >> T;
	cin.ignore();
	while (T--) {
		string s;
		int token;
		getline(cin, s);
		vector<int> A;
		istringstream ss(s);
		while (ss >> token)
			A.push_back(token);
		cout << maximumValue(A) << endl;		
	}
    return 0;
}