/*
Problem Statement: https://leetcode.com/problems/climbing-stairs/
*/

class Solution {
public:
    int climbStairs(int n) {
        int f0, f1, f2;
        f0 = 0;
        f1 = 1;
        while (n--) {
            f2 = f0 + f1;
            f0 = f1;
            f1 = f2;
        }
        return f2;
    }
};