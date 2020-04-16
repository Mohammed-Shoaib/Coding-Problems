#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool length_compare(string& l, string& r) {
	return l.length() > r.length();
}

bool starts_with(string& s, string& prefix) {
	return equal(prefix.begin(), prefix.end(), s.begin());
}

bool ends_with(string& s, string& suffix) {
	return equal(suffix.rbegin(), suffix.rend(), s.rbegin());
}

vector<string> split(string& s) {
	string token;
	istringstream ss(s);
	vector<string> words;
	while (getline(ss, token, '*'))
		words.push_back(token);
	if (s.back() == '*')
		words.push_back("");
	return words;
}

string pattern_matching(int N, vector<string>& P) {
	string mid, s = "*";
	vector<string> pre, suf;

	// distribute patterns into prefix, suffix, and middle
	for (string& p: P) {
		vector<string> words = split(p);
		if (!words.front().empty())
			pre.push_back(words.front());
		if (!words.back().empty())
			suf.push_back(words.back());
		for (int i = 1; i < words.size() - 1; i++)
			mid += words[i];
	}
	
	// sort by length in descending order
	sort(pre.begin(), pre.end(), length_compare);
	sort(suf.begin(), suf.end(), length_compare);
	
	// check if prefix matches longest prefix
	for (string& prefix: pre) {
		if (s.front() == '*')
			s = prefix + s;
		else if (!starts_with(s, prefix))
			return "*";
	}

	// check if suffix matches longest suffix
	for (string& suffix: suf) {
		if (s.back() == '*')
			s = s + suffix;
		else if (!ends_with(s, suffix))
			return "*";
	}

	// add middle characters and remove '*'
	s.insert(s.find('*'), mid);
	s.erase(remove(s.begin(), s.end(), '*'), s.end());
	
	return s;
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int N;
		cin >> N;
		vector<string> P(N);
		for (int i = 0; i < N; i++)
			cin >> P[i];
		cout << "Case #" << x << ": " << pattern_matching(N, P) << endl;
	}
	return 0;
}