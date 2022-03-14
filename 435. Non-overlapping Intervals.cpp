//https://leetcode.com/problems/non-overlapping-intervals/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int size = intervals.size();
        
        if (size == 0)
            return 0;
        
        sort(intervals.begin(), intervals.end());
        
        int ans = 0;
        
        vector<int> prev = intervals[0];
        
        for (int i=1; i<size; i++) {
            if (intervals[i][1] < prev[1]) {
                ans++;
                prev = intervals[i];
                continue;
            } else if (intervals[i][0] < prev[1]) {
                ans++;
                continue;
            }
            else 
                prev = intervals[i];
        }
        
        return ans;
        
    }
};
