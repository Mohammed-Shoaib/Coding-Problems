/*
Problem Statement: https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/
*/

class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int low, mid, high, sum;
		low = 1;
		high = *max_element(arr.begin(), arr.end()) + 1;
		
		while (low < high) {
			mid = (low + high) / 2;
			sum = get_sum(mid, arr);
			if (target <= sum)
				high = mid;
			else
				low = mid + 1;
		}
		
		if (abs(target - get_sum(low - 1, arr)) <= abs(target - get_sum(low, arr)))
			low--;
		
		return low;
    }

	int get_sum(int x, vector<int> arr) {
		for (int i = 0; i < arr.size(); i++)
			if (arr[i] > x)
				arr[i] = x;
		return accumulate(arr.begin(), arr.end(), 0);
	}
};