//https://leetcode.com/problems/swim-in-rising-water/


class Solution {
public:
    
    int swimInWater(vector<vector<int>>& grid) {
        
        int rows = grid.size();
        
        if (!rows) return 0;
        
        int cols = grid[0].size();
        
        priority_queue< tuple<int,int,int>, 
                        vector<tuple<int,int,int>>, 
                        greater<tuple<int,int,int>>> pq;
        
        pq.push({grid[0][0], 0, 0});
        
        int ans = 0;
        while(true) {
            
            tuple<int, int,int> t = pq.top();
            pq.pop();
            
            int dist = get<0>(t);
            int i = get<1>(t);
            int j = get<2>(t);
            
            ans = max(ans, dist);
            if (i == rows-1 && j == cols-1)
                return ans;
            
            grid[i][j] = -1;
            
            if (i+1 < rows && grid[i+1][j] != -1) pq.push({grid[i+1][j], i+1, j});
            if (j+1 < cols && grid[i][j+1] != -1) pq.push({grid[i][j+1], i, j+1});
            if (i-1 >= 0 && grid[i-1][j] != -1) pq.push({grid[i-1][j], i-1, j});
            if (j-1 >= 0 && grid[i][j-1] != -1) pq.push({grid[i][j-1], i, j-1});

        }
        
        return ans;
        
    }
    
    
};
