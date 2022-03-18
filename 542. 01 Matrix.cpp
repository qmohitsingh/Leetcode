//https://leetcode.com/problems/01-matrix/

class Solution {
public:
    
    unordered_map<string, int> visited;
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int rows = mat.size();
        
        if (!rows) return mat;
        
        int cols = mat[0].size();
        
        for(int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                if (mat[i][j] && !hasNeighbours(mat, i, j)) {
                    mat[i][j] = mat.size() + mat[0].size() + 1;
                }
            }
        }
        
        for(int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                if (mat[i][j] == 1) {
                    cout<<"dfs"<<endl;
                    dfs(mat, i, j, 1);
                }
            }
        }
        
        return mat;
    }
    
    void dfs(vector<vector<int>>& mat, int i, int j, int val) {
        
        if (i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size() || mat[i][j] < val)
            return;
        
        mat[i][j] = val;
        
        dfs(mat, i, j-1, val+1);
        dfs(mat, i, j+1, val+1);
        dfs(mat, i+1, j, val+1);
        dfs(mat, i-1, j, val+1);
        
    }
    
    bool hasNeighbours(vector<vector<int>> mat, int i, int j) {
        
        if (i-1 >=0 && mat[i-1][j] == 0) return true;
        
        if (i+1 < mat.size() && mat[i+1][j] == 0) return true;
        
        if (j-1 >=0 && mat[i][j-1] == 0) return true;
        
        if (j+1 < mat[0].size() && mat[i][j+1] == 0) return true;
        
        return false;
        
    }
};
