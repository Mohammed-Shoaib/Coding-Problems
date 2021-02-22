/*
Problem Statement: https://leetcode.com/problems/count-largest-group/
*/

class Solution {
public:
	int countLargestGroup(int n) {
		int size, max_f;
		unordered_map<int, int> freq;
		size = max_f = 0;
		for (int i = 1; i <= n; i++)
			max_f = max(++freq[f(i)], max_f);
		for (auto& [k, v]: freq)
			size += (v == max_f);
		return size;
	}

	int f(int n) {
		int sum = 0;
		while (n) {
			sum += n % 10;
			n /= 10;
		}
		return sum;
	}
};