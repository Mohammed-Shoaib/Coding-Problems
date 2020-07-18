/*
Problem Statement: https://leetcode.com/problems/top-k-frequent-words/
Time: O(n + k • log k)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		vector<string> res(k);
		unordered_map<string, int> freq;

		// helper function to compare words
		auto compare = [](auto& l, auto& r) {
			if (l.second == r.second)
				return l.first < r.first;
			else
				return l.second > r.second;
		};

		// count occurrences of each word
		for (string& word: words)
			freq[word]++;
		vector<pair<string, int>> v(freq.begin(), freq.end());
		
		// sort first k elements by count in decreasing order
		nth_element(v.begin(), v.begin() + k - 1, v.end(), compare);
		sort(v.begin(), v.begin() + k, compare);

		// get top k elements using sorted vector
		for (int i = 0; i < k; i++)
			res[i] = move(v[i].first);
		
		return res;
	}
};