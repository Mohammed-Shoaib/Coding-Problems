/*
Problem Statement: https://leetcode.com/problems/valid-perfect-square/
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        // newton's method
        long long x = num;
        while (x * x > num)
            x = (x + num / x) / 2;
        return (x * x == num);
    }
};