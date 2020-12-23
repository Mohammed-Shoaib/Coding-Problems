/*
Problem Statement: https://leetcode.com/problems/unique-email-addresses/
Time: O(n • len)
Space: O(n • len)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int numUniqueEmails(vector<string>& emails) {
		unordered_set<string> seen;
		
		for (string& email: emails) {
			int pos = email.find('@');
			string filter, address = email.substr(0, pos);
			
			for (char& c: address) {
				if (c == '+')
					break;
				else if (c != '.')
					filter += c;
			}
			
			seen.insert(filter + email.substr(pos));
		}
		
		return seen.size();
	}
};