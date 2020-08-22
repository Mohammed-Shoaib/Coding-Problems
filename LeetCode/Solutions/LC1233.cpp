/*
Problem Statement: https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/
*/

class Solution {
public:
	vector<string> removeSubfolders(vector<string>& folder) {
		string parent = "#";
		vector<string> res;
		
		sort(folder.begin(), folder.end());
		
		for (int i = 0; i < folder.size(); i++)
			if (folder[i].substr(0, parent.length()) != parent) {
				parent = folder[i] + "/";
				res.push_back(folder[i]);
			}
		
		return res;
	}
};