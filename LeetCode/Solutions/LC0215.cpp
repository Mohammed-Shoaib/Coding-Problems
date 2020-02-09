/*
Problem Statement: https://leetcode.com/problems/kth-largest-element-in-an-array/
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        quick_select(0, nums.size() - 1, --k, nums);
        return nums[k];
    }

    void quick_select(int i, int j, int k, vector<int>& nums) {
        int q = partition(i, j, nums);
        if (q == k)
            return;
        else if (q > k)
            quick_select(i, q - 1, k, nums);
        else
            quick_select(q + 1, j, k, nums);
    }

    int partition(int i, int j, vector<int>& nums) {
        int k = i;
        while (i < j) {
            if (nums[i] > nums[j])
                swap(nums[k++], nums[i]);
            i++;
        }
        swap(nums[k], nums[j]);
        return k;
    }
};