/*
Problem Statement: https://www.hackerrank.com/challenges/acm-icpc-team/problem
*/

#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#define M 500

using namespace std;

vector<int> acmTeam(vector<string> topic) {
	int known;
	vector<int> ans(2);
	for (int i = 0; i < topic.size() - 1; i++) {
		bitset<M> b1(topic[i]);
		for (int j = i + 1; j < topic.size(); j++) {
			bitset<M> b2(topic[j]);
			known = (b1 | b2).count();
			if (known > ans[0]) {
				ans[0] = known;
				ans[1] = 1;
			} 
			else if (known == ans[0])
				ans[1]++;
		}
	}
	return ans;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> ans;
	vector<string> topic(n);
	for (int i = 0; i < n; i++)
		cin >> topic[i];
	ans = acmTeam(topic);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
	return 0;
}