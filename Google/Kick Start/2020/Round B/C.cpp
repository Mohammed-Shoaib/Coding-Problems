#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <stack>
#include <utility>
#include <functional>
#include <unordered_map>

using namespace std;

pair<int, int> robot_path_decoding(string& S) {
	int mod, N;
	mod = 1e9;
	N = S.length();
	stack<int> st;
	vector<int> close(N);
	unordered_map<char, pair<int, int>> move{{'N', {0, -1}}, {'S', {0, 1}}, {'E', {1, 0}}, {'W', {-1, 0}}};

	// get position of closing parenthesis for each opening parenthesis
	for (int i = 0; i < N; i++) {
		if (S[i] == '(')
			st.push(i);
		else if (S[i] == ')') {
			close[st.top()] = i;
			st.pop();
		}
	}

	// calculate position after evaluating subprogram from [l, r]
	function<pair<int, int>(int, int)> evaluate = [&](int l, int r) {
		pair<int, int> pos;
		for (int i = l; i <= r; i++) {
			if (isdigit(S[i])) {
				long long digit = S[i] - '0';
				pair<int, int> p = evaluate(i + 2, close[i + 1] - 1);
				pos.first = (pos.first + digit * p.first) % mod;
				pos.second = (pos.second + digit * p.second) % mod;
				i = close[i + 1];
			} else if (isalpha(S[i])) {
				pos.first = (pos.first + move[S[i]].first) % mod;
				pos.second = (pos.second + move[S[i]].second) % mod;
			}
			if (pos.first < 0)
				pos.first += mod;
			if (pos.second < 0)
				pos.second += mod;
		}
		return pos;
	};

	return evaluate(0, N - 1);
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		string S;
		cin >> S;
		pair<int, int> pos = robot_path_decoding(S);
		cout << "Case #" << x << ": " << pos.first + 1 << " " << pos.second + 1 << endl;
	}
	return 0;
}