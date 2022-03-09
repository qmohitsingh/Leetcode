//https://leetcode.com/problems/convert-1d-array-into-2d-array/

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        
        if (original.size() != m*n) 
            return vector<vector<int>>();
        
        vector<vector<int>> ans(m, vector<int>(n));
        
        int pointer = 0;
        for (int i=0; i<m; i++)
            for(int j=0; j<n; j++) {
                ans[i][j] = original[pointer++];
            }
        
        return ans;
        
    }
};
