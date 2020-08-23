// Problem Code: LCPESY

#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

int longestCommonPattern(string A, string B) {
	int common = 0;
	unordered_map<char, int> mapA, mapB;
	for (int i = 0 ; i < A.length() ; i++)
		mapA[A[i]]++;
	for (int i = 0 ; i < B.length() ; i++)
		mapB[B[i]]++;
	for (auto it : mapA)
		common += min(mapA[it.first], mapB[it.first]);
	return common;
}

int main() {
	int T;
	string A, B;
	cin >> T;
	while (T--) {
		cin >> A >> B;
		cout << longestCommonPattern(A, B) << endl;
	}
	return 0;
}