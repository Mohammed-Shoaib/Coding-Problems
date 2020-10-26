// Problem Code: 1056A

#include <iostream>
#include <vector>

using namespace std;

void determineLine(vector<vector<int>>& lines) {
	vector<int> count(101);
	for (int i = 0 ; i < lines.size() ; i++)
		for (int j = 0 ; j < lines[i].size() ; j++)
			count[lines[i][j]]++;
	for (int i = 1 ; i < count.size() ; i++)
		if (count[i] == lines.size())
			cout << i << " ";
	cout << endl;
}

int main() {
	int n, r, num;
	vector<int> line;
	vector<vector<int>> lines;
	cin >> n;
	while (n--) {
		cin >> r;
		for (int i = 0 ; i < r ; i++) {
			cin >> num;
			line.push_back(num);
		}
		lines.push_back(line);
		line.clear();
	}
	determineLine(lines);
	return 0;
}