// Problem Code: 1234C

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string water_flow(int n, vector<string>& pipes) {
	int i, j;
	i = j = 0;
	while (j < n) {
		if (pipes[i][j] > '2') {
			i ^= 1;
			if (pipes[i][j] <= '2')
				return "NO";
		}
		j++;
	}
	return (i == 1) ? "YES" : "NO";
}

int main() {
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		vector<string> pipes(2);
		for (int i = 0; i < pipes.size(); i++)
			cin >> pipes[i];
		cout << water_flow(n, pipes) << endl;
	}
	return 0;
}