/*
Problem Statement: https://leetcode.com/problems/jump-game-iii/
*/

class Solution {
private:
	unordered_set<int> seen;
public:
    bool canReach(vector<int>& arr, int start) {
		if (start >= 0 && start < arr.size() && seen.insert(start).second)
			return arr[start] == 0 || canReach(arr, start - arr[start]) || canReach(arr, start + arr[start]);
		return false;
    }
};