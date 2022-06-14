// Reference : https://leetcode.com/problems/search-a-2d-matrix-ii/


class Solution {
public:
    
    // Time Complexity T : O(n+m), Space Complexity : O(1)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        
        int rows = matrix.size();
        
        if (!rows) return false;
        
        int cols = matrix[0].size();
        
        int r = 0, c = cols-1;
        while(r < rows && c >= 0) {
            
            if (matrix[r][c] == target) return true;
            
            if (matrix[r][c] > target) {
                c--;
            } else {
                r++;
            }
                
        }
        
        return false;
        
    }
};
