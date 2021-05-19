/*
Problem Statement: https://leetcode.com/problems/find-duplicate-file-in-system/
Time: O(paths)
Space: O(paths)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<vector<string>> findDuplicate(vector<string>& paths) {
		vector<vector<string>> dups;
		unordered_map<string, vector<string>> mp;
		
		for (string& path: paths) {
			string token, root, file_name, content;
			istringstream ss(path);
			ss >> root;
			root += '/';
			
			while (ss >> token) {
				int pos = token.find('(');
				file_name = root + token.substr(0, pos);
				content = token.substr(pos + 1);
				content.pop_back();
				mp[content].push_back(file_name);
			}
		}
		
		for (auto& [k, v]: mp)
			if (v.size() > 1)
				dups.push_back(move(v));
		
		return dups;
	}
};