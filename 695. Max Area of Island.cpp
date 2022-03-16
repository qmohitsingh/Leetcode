//https://leetcode.com/problems/max-area-of-island/

class Solution {
public:
    int ans = 0;
    int count = 0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int rows = grid.size();
        
        if (!rows) return ans;
        
        int cols = grid[0].size();
        
        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                if (grid[i][j]) {
                    count = 0;
                    dfs(grid, i, j);
                }
            }
        }
        
        return ans;
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j) {
        
        ans = max(ans, count);
        
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || !grid[i][j]) {
            return;
        }
        
        count++; grid[i][j] = 0;
        
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);
        
    }
};

