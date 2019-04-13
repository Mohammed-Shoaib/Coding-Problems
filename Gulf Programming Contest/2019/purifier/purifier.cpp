#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string purifier(int X, int Y, vector<int> &h1, vector<int> &m1, vector<int> &h2, vector<int> &m2) {
	int free, busy = Y * 10 * 60;
	for (int i = 0; i < h1.size(); i++)
		busy += (h2[i] * 60 + m2[i]) - (h1[i] * 60 + m1[i]) + 1;
	free = Y * 24 * 60 - busy;
	return (free >= X * 60) ? "Yes" : "No";
}

int main() {
	freopen("purifier.in", "r", stdin);
	freopen("output.out", "w", stdout);
	
	int N, k = 1;
	cin >> N;
	while (N--) {
		int X, Y;
		cin >> X >> Y;
		cin.ignore();
		vector<int> h1, m1, h2, m2;
		for(int i = 0; i < Y; i++) {
			string line, s, token;
			getline(cin, line);
			if (line == "-")
				continue;
			istringstream sl(line);
			while (sl >> s) {
				istringstream ss(s);
				getline(ss, token, ':');
				h1.push_back(stoi(token));
				getline(ss, token, '-');
				m1.push_back(stoi(token));
				getline(ss, token, ':');
				h2.push_back(stoi(token));
				ss >> token;
				m2.push_back(stoi(token));
			}
		}
		cout << k << ". " << purifier(X, Y, h1, m1, h2, m2) << endl;
		k++;
	}
	
	return 0;
}