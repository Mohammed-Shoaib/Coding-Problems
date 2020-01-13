/*
Problem Statement: https://leetcode.com/problems/container-with-most-water/
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int low, high, water, h;
        low = water = 0;
        high = height.size() - 1;
        while (low < high) {
            h = min(height[low], height[high]);
            water = max((high - low) * h, water);
            if (height[low] < height[high])
                low++;
            else
                high--;
        }
        return water;
    }
};