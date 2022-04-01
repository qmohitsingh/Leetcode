//https://leetcode.com/problems/coloring-a-border/

class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        
        
        dfs(grid, row, col, grid[row][col]);
        
        for (int i=0; i<grid.size(); i++)
            for (int j=0; j<grid[0].size(); j++) 
                if (grid[i][j] < 0) 
                    grid[i][j] = color;
            
        
        return grid;
    }
    
    
    void dfs(vector<vector<int>>& grid, int row, int col, int current) {
        
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] != current) 
            return;
        
        grid[row][col] = -current;
        
        dfs(grid, row+1, col, current);
        dfs(grid, row-1, col, current);;
        dfs(grid, row, col+1, current);
        dfs(grid, row, col-1, current);
        
        if (row > 0 && row < grid.size() -1    && 
            col > 0 && col < grid[0].size() -1 && 
            current == abs(grid[row+1][col])   &&
            current == abs(grid[row-1][col])   &&
            current == abs(grid[row][col+1])   && 
            current == abs(grid[row][col-1])) 
            grid[row][col] = current;
        
    }
};
