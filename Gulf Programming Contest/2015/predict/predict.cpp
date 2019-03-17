#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> predict(string Q, vector<string> dict) {
	vector<string> res;
	for (int i = 0; i < dict.size() && res.size() < 3; i++)
		if (Q == string(dict[i].begin(), dict[i].begin() + Q.size()))
			res.push_back(dict[i]);
	if (res.size() == 0)
			res.push_back(Q);
	return res;
}

int main() {
	freopen("predict.in", "r", stdin);
	freopen("output.out", "w", stdout);
	
	int N;
	while (cin >> N && N) {
		string Q;
		vector<string> dict(N), res;
		for (int i = 0; i < N; i++)
			cin >> dict[i];
		while (cin >> Q && Q != "###") {
			res = predict(Q, dict);
			cout << Q << ":";
			for (int i = 0; i < res.size(); i++)
				cout << " " << res[i];
			cout << endl;
		}
	}
	return 0;
}
