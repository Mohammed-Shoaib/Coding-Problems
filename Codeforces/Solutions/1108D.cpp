// Problem Code: 1108D

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

vector<char> rgb({'R', 'G', 'B'});

char next(char c) {
	int i;
	for (i = 0; i < rgb.size(); i++)
		if (c == rgb[i])
			break;
	i = (i + 1) % rgb.size();
	return rgb[i];
}

char next(char c1, char c2) {
	int i, j, k;
	for (i = 0; i < rgb.size(); i++)
		if (c1 == rgb[i])
			break;
	for (j = 0; j < rgb.size(); j++)
		if (c2 == rgb[j])
			break;
	k = rgb.size() - (i + j);
	return rgb[k];
}

int change(int pos, int len, char c, string &s) {
	int count = 0;
	len /= 2;
	while (len--) {
		s[pos] = c;
		pos -= 2;
		count++;
	}
	return count;
}

void diverseGarland(int n, string s) {
	int len, pos, count;
	char c;
	vector< pair<int, int> > blocks;
	count = 0;
	len = 1;
	
	for (int i = 1; i < n; i++) {
		if (s[i] == s[i - 1])
			len++;
		else {
			pos = i;
			blocks.push_back(make_pair(len, pos));
			len = 1;
		}
	}
	pos = n;
	blocks.push_back(make_pair(len, pos));
	
	for (int i = 0; i < blocks.size() - 1; i++) {
		len = blocks[i].first;
		if (len == 1)
			continue;
		else if (len & 1) {
			pos = blocks[i].second - 2;
			c = next(s[pos]);
		} else {
			pos = blocks[i].second - 1;
			c = next(s[pos], s[pos + 1]);
		}
		count += change(pos, len, c, s);
	}

	len = blocks[blocks.size() - 1].first;
	pos = n - 1;
	if (len & 1)
		pos--;
	c = next(s[pos]);
	count += change(pos, len, c, s);
	
	cout << count << endl;
	cout << s << endl;
}

int main() {
	int n;
	string s;
	cin >> n >> s;
	diverseGarland(n, s);
	return 0;
}