#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <limits>
#include <sstream>
#include <algorithm>

using namespace std;

int rows = 2, cols = 3;

int compute(vector<int> widths, vector< vector<string> >& words) {
	int len;
	vector<int> lines(cols);
	
	for (int i = 0; i < words.size(); i++) {
		if (i % cols == 0)
			fill(lines.begin(), lines.end(), *max_element(lines.begin(), lines.end()));
		
		for (int j = 0, w = -1; j < words[i].size(); j++) {
			len = words[i][j].length() + 1;
			if (w + len > widths[i % cols]) {
				w = -1;
				lines[i % cols]++;
			}
			w += len;
		}
		
		lines[i % cols]++;
	}

	return *max_element(lines.begin(), lines.end());
}

int table(int k, vector< vector<string> >& words) {
	int min_l = numeric_limits<int>::max();
	vector<int> max_w(cols);

	for (int i = 0; i < words.size(); i++)
		for (string& word: words[i])
			max_w[i % cols] = max((int) word.length(), max_w[i % cols]);

	for (int w1 = max_w[0]; w1 < k; w1++)
		for (int w2 = max_w[1]; w2 < k; w2++) {
			int w3 = k - (w1 + w2);
			if (w3 < max_w[2])
				break;
			min_l = min(compute({w1, w2, w3}, words), min_l);
		}

	return min_l;
}

int main() {
	freopen("table.in", "r", stdin);
	freopen("output.out", "w", stdout);

	int k;
	while (cin >> k && k) {
		cin.ignore();
		vector< vector<string> > words(rows * cols);
		for (int i = 0; i < words.size(); i++) {
			string token, line;
			getline(cin, line);
			istringstream ss(line);
			while (getline(ss, token, ' '))
				words[i].push_back(token);
		}
		cout << table(k, words) << endl;
	}

	return 0;
}