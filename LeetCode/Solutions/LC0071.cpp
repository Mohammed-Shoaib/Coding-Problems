/*
Problem Statement: https://leetcode.com/problems/set-matrix-zeroes/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	string simplifyPath(string path) {
		string token;
		vector<string> paths;
		istringstream ss(exchange(path, ""));
		unordered_set<string> seen = { "", ".", ".." };
		
		while (getline(ss, token, '/')) {
			if (token == ".." && !paths.empty())
				paths.pop_back();
			else if (!seen.count(token))
				paths.push_back(token);
		}
		
		for (string& x: paths)
			path += '/' + x;
		if (path.empty())
			path = '/';
		
		return path;
	}
};