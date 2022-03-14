//https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> ans;
        
        sort(intervals.begin(), intervals.end());
        
        vector<int> compare = intervals[0];
        
        for (int i=0; i< intervals.size(); i++) {
            if (compare[1] >= intervals[i][1]){
                continue;
            } else if (compare[1] >= intervals[i][0]) {
                int a = compare[0];
                int b = intervals[i][1];
                compare = {a,b};
            } else {
                ans.push_back(compare);
                compare = intervals[i];
            }
        }
        
        ans.push_back(compare);
        
        return ans;
        
    }
};
