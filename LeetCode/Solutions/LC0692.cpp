/*
Problem Statement: https://leetcode.com/problems/top-k-frequent-words/
*/

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
		vector<string> ele;
		unordered_map<string, int> freq;

		// Count occurrences of each word
		for (string& word: words)
			freq[word]++;
		vector< pair<string, int> > v(freq.begin(), freq.end());
		
		// Sort first k elements by count in decreasing order
		nth_element(v.begin(), v.begin() + k - 1, v.end(), compare);
		sort(v.begin(), v.begin() + k, compare);

		// Use sorted vector to create vector of k elements
		transform(v.begin(), v.begin() + k, back_inserter(ele), [](auto& p) { return p.first; });
		
		return ele;
    }

	static bool compare(pair<string, int>& l, pair<string, int>& r) {
		if (l.second == r.second)
				return l.first < r.first;
		else
			return l.second > r.second;
	}
};