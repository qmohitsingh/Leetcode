//https://leetcode.com/problems/island-perimeter/

class Solution {
public:
    
    void dfs(int i, int j, int rows, int columns, vector<vector<int>> & grid, int & ans) {
        
        if (i < 0 || j < 0 || i >= rows || j >= columns || grid[i][j] == 0)  {
            ans += 1;
            return;
        }
        
        if ( grid[i][j] == -1) return;
        
        grid[i][j] = -1;
        
        dfs(i-1, j, rows, columns, grid, ans);
        dfs(i+1, j, rows, columns, grid, ans);
        dfs(i, j-1, rows, columns, grid, ans);
        dfs(i, j+1, rows, columns, grid, ans);
            
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int ans = 0;
        
        int rows = grid.size();
        int columns = grid[0].size();
        
        for (int i=0; i<rows; i++)
            for (int j=0; j<columns; j++) {
                if (grid[i][j] == 1) {
                   dfs(i,j,rows,columns,grid, ans);
                }
            }
        
        return ans;
        
    }
};
