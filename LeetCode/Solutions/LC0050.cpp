/*
Problem Statement: https://leetcode.com/problems/powx-n/
*/

class Solution {
public:
    double myPow(double x, long long n) {
        double y = pow(x, abs(n));
        return (n >= 0) ? y : 1 / y;
    }

    double pow(double x, long long n) {
        if (n == 0)
            return 1;
        double y = pow(x, n / 2);
        y *= y;
        return (n & 1) ? x * y : y;
    }
};