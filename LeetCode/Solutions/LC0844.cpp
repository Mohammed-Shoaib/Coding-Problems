/*
Problem Statement: https://leetcode.com/problems/backspace-string-compare/
*/

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int s_len = assign(S), t_len = assign(T);
        
        if (s_len != t_len)
            return false;
        
        for (int i = 0; i < s_len; i++)
            if (S[i] != T[i])
                return false;
        
        return true;
    }

    int assign(string& s) {
        int i = 0;
        for (char& c: s) {
            if (c == '#')
                i = max(0, i - 1);
            else
                s[i++] = c;
        }
        return i;
    }
};