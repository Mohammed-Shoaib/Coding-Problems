#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <functional>

using namespace std;

unordered_map<int, bool> squares;

void square(int N, vector<int>& a) {
	vector<int> seq;
	vector<bool> visited(N);
	vector< vector<int> > adj(N);
	
	sort(a.begin(), a.end());
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
			if (squares.count(a[i] + a[j])) {
				adj[i].push_back(j);
				adj[j].push_back(i);
			}

	function<bool(int)> sequence = [&](int s) {
		visited[s] = true;
		seq.push_back(a[s]);

		if (seq.size() == N)
			return true;

		for (int& u: adj[s])
			if (!visited[u] && sequence(u))
				return true;
		
		seq.pop_back();
		visited[s] = false;
		return false;
	};

	for (int i = 0; i < N && !sequence(i); i++) {
		seq.clear();
		fill(visited.begin(), visited.end(), false);
	}
	
	if (seq.empty())
		cout << "No solution";
	else
		for (int i = 0; i < N; i++)
			cout << seq[i] << " ";
	cout << endl;
}

int main() {
	freopen("square.in", "r", stdin);
	freopen("output.out", "w", stdout);
	
	// preprocess
	for (int i = 1; i < 10; i++)
		squares[i * i] = true;

	int N;
	while (cin >> N && N) {
		vector<int> a(N);
		for (int i = 0; i < N; i++)
			cin >> a[i];
		square(N, a);
	}
	
	return 0;
}