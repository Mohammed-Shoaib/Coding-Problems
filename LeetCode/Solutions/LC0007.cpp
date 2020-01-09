/*
Problem Statement: https://leetcode.com/problems/reverse-integer/
*/

class Solution {
public:
    int reverse(int x) {
        long long rev = 0;
        while (x != 0) {
        	rev *= 10;
        	rev += x % 10;
        	x /= 10;
        }
        if (rev < INT_MIN || rev > INT_MAX)
        	rev = 0;
        return rev;
    }
};