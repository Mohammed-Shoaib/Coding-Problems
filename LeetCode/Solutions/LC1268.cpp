/*
Problem Statement: https://leetcode.com/problems/search-suggestions-system/
*/

class Solution {
public:
	vector<vector<string>> suggestedProducts(vector<string>& products, string& searchWord) {
		string s;
		auto it = products.begin();
		vector<vector<string>> suggest(searchWord.size(), vector<string>());
		
		sort(products.begin(), products.end());
		
		for (int j, i = 0; i < searchWord.size(); i++) {
			s += searchWord[i];
			it = lower_bound(it, products.end(), s);
			j = distance(products.begin(), it);
			
			while (j < products.size() && suggest[i].size() < 3 && products[j].find(s) != string::npos)
				suggest[i].push_back(products[j++]);
		}
		
		return suggest;
	}
};