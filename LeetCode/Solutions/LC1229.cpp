/*
Problem Statement: https://leetcode.com/problems/meeting-scheduler/
*/

class Solution {
public:
    vector<int> minAvailableDuration(vector< vector<int> >& slots1, vector< vector<int> >& slots2, int duration) {
        int start, end, i, j;
        
        i = j = 0;
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());

        while (i < slots1.size() && j < slots2.size()) {
            start = max(slots1[i][0], slots2[j][0]);
            end = min(slots1[i][1], slots2[j][1]);
            
            if (start + duration <= end)
                return {start, start + duration};
            else if (slots1[i][1] < slots2[j][1])
                i++;
            else
                j++;
        }

        return {};
    }
};