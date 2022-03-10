//https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

class Solution {
public:
    
    //Naive Solution : O(n*m), Optimized Solution : O(nlogn), Star Pattern : O(m+n)
    int countNegatives(vector<vector<int>>& grid) {
        
        int row = grid.size()-1;
        int column = 0;
        
        int ans = 0;
        while(row >= 0 && column < grid[0].size()) {
            
            if (grid[row][column] < 0) {
                row--;
                ans += grid[0].size() - column; 
            } else {
                column++;
            }
        }
        
        return ans;
        
    }
    
};
