// Problem Code: 1108C

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string change(string s, vector<char> rgb) {
	for (int i = 0, j = 0; i < s.length(); i++, j++, j %= 3)
		s[i] = rgb[j];
	return s;
}

void niceGarland(int n, string s) {
	int start;
	vector<int> sum(6);
	vector< vector<char> > rgb({
		{'R', 'G', 'B'},
		{'R', 'B', 'G'},
		{'G', 'R', 'B'},
		{'G', 'B', 'R'},
		{'B', 'G', 'R'},
		{'B', 'R', 'G'}
	});
	for (int i=0 ; i < s.length() ; i++)
		for (int j=0 ; j < rgb.size() ; j++) {
			int k = i % 3;
			if (s[i] != rgb[j][k])
				sum[j]++;
		}
	start = distance(sum.begin(), min_element(sum.begin(), sum.end()));
	s = change(s, rgb[start]);
	cout << sum[start] << endl;
	cout << s << endl;
}

int main() {
	int n;
	string s;
	cin >> n >> s;
	niceGarland(n, s);
	return 0;
}