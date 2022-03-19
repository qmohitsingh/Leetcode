//https://leetcode.com/problems/maximal-square/

class Solution {
public:
    
    
    bool isValidSquare(vector<vector<char>>& mat, int i, int j, int len) {
        
        
        int rows = i+len-1;
        int cols = j+len-1;
        
        bool flag = true;
        for (int k=i; k <= rows; k++) {
            for (int l=j; l <= cols; l++) {
                if (mat[k][l] != '1') 
                    return false;
            }
        }
        
        return true;
        
    }
    
    int getMaxSquare(vector<vector<char>>& mat, int row, int col) {
        
        int ones = min(mat.size()-row, mat[0].size()-col);
        int len = 0;
        
        int j = 0;
        for (int i=0; i<ones; i++) {
            for (j=0; j<ones && mat[i+row][j+col]!='0'; j++);
            ones = j;
            len = min(ones, i+1);
        }
        
        return len;
        
    }
    
    int maximalSquare(vector<vector<char>>& mat) {
        
        int rows = mat.size();
        
        if (!rows) return 0;
        
        int cols = mat[0].size();
        
        // int ans = 0;
        // for (int i=0; i<rows; i++) {
        //     for (int j=0; j<cols; j++) {
        //         for (int side = min(rows-i, cols-j); side; side--)
        //             if (isValidSquare(mat, i, j, side))
        //                 ans = max(ans, side*side);
        //     }
        // }
        
        // for (int side = min(rows, cols); side; side--)
        //     for (int i=0; i<=rows-side; i++) 
        //         for (int j=0; j<=cols-side; j++) 
        //             if (isValidSquare(mat, i, j, side))
        //                 return side*side;
        
        
        // int ans = 0;
        // for (int i=0; i<rows; i++) {
        //         for (int j=0; j<cols; j++) {
        //             ans = max(ans, getMaxSquare(mat, i, j));
        //         }
        //     }
        
        vector<vector<int>> dp(rows+1, vector<int>(cols+1, 0));
        
        int ans = 0;
        for (int i=1; i<=rows; i++){
            for (int j=1; j<=cols; j++) {
                if (mat[i-1][j-1] == '1') {
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }
                
        return ans*ans;
    }
};
