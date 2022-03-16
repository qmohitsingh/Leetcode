//https://leetcode.com/problems/flood-fill/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int rows = image.size();
        
        if (!rows) return image;
        
        if (image[sr][sc] == newColor) 
            return image;
        
        int cols = image[0].size();

        dfs(image, sr, sc, newColor, image[sr][sc]);
        
        return image;
        
    }
    
    void dfs(vector<vector<int>>& image, int i, int j, int newColor, int prevColor) {

        if (i < 0 || j < 0 || i >= image.size() 
            || j >= image[0].size() || image[i][j] != prevColor) {
           return; 
        }
        
        image[i][j] = newColor;
        
        dfs(image, i+1, j, newColor, prevColor); 
        dfs(image, i-1, j, newColor, prevColor); 
        dfs(image, i, j+1, newColor, prevColor); 
        dfs(image, i, j-1, newColor, prevColor); 
        
    }
};
