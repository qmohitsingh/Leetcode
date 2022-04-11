https://leetcode.com/problems/shift-2d-grid/

Reference : https://github.com/niveditaprity/LeetCode/blob/master/April%20Leetcode%20Challenge/1260.%20Shift%202D%20Grid.cpp
   
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
       vector<vector<int>>ans(grid.size(),vector<int>(grid[0].size(),0));
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                ans[(i+(j+k)/grid[i].size())%grid.size()][(j+k)%grid[i].size()]=grid[i][j];
            }
        }
        return ans;
    }
};
