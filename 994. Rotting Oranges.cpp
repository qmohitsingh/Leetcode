//https://leetcode.com/problems/rotting-oranges/


class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        int rows = grid.size();
        
        if (!rows) return 0;
        
        int cols = grid[0].size();
        
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        
        queue<pair<int,int>> q;
        for (int i=0; i<rows; i++)
            for (int j=0; j<cols; j++) {
                if (grid[i][j] == 2) {
                    q.push({i,j});
                    visited[i][j] = 1;
                }
            }
        
        int ans = 0;
        int cells = 0;
        while(!q.empty()) {
            
            for(int k = size(q); k; k--) {
                
                pair<int, int> p = q.front(); q.pop();
                
                int i = p.first, j = p.second;
                
                if (i+1 < rows && !visited[i+1][j] && grid[i+1][j]) {
                    visited[i+1][j] = 1;
                    q.push({i+1, j});
                }
            
                if (i-1 >= 0 && !visited[i-1][j] && grid[i-1][j])  {
                    visited[i-1][j] = 1;
                    q.push({i-1, j});
                }
                    
                if (j+1 < cols && !visited[i][j+1] && grid[i][j+1]) {
                    visited[i][j+1] = 1;
                    q.push({i, j+1});
                }
                
                if (j-1 >= 0  && !visited[i][j-1] && grid[i][j-1]) {
                    visited[i][j-1] = 1;
                    q.push({i, j-1});
                }
            }
            if (!q.empty()) ans++;
        }
        
        for (int i=0; i<rows; i++)
            for (int j=0; j<cols; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) 
                    return -1;
            }
        
        return ans;
        
    }
};
