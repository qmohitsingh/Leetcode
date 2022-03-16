//https://leetcode.com/problems/largest-rectangle-in-histogram/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int size = heights.size();
        
        stack<pair<int,int>> stk;
        
        int ans = INT_MIN;
        for (int i=0; i<size; i++) {
            
            int index = i;
            while (!stk.empty() && stk.top().second > heights[i] ) {           
                index = stk.top().first;
                ans = max(ans, stk.top().second*(i-index));
                stk.pop();
            }
            
            stk.push({index, heights[i]});
        }
        
        while(!stk.empty()) {
            int index = stk.top().first;
            ans = max(ans, stk.top().second*(size-index));
            stk.pop();
        }
        
        return ans;
    }
};

// 1 2 5
