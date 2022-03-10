//https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers/

class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        
        
        int rows = matrix.size();
        
        if (rows == 0) 
            return true;
        
        int columns = matrix[0].size();
        
        if (rows != columns)
            return false;
        
        vector<int> rmap(rows + 1, 0), cmap(rows+1,0);
        
        for (int i=0; i<rows; i++) {
            
            // Mapping values
            for (int j=0; j<columns; j++) {
                rmap[matrix[i][j]]++;
                cmap[matrix[j][i]]++;
            }
 
            // Checking map 
            for (int i=1; i<=matrix.size(); i++) {
                if (rmap[i] != 1 || cmap[i] != 1) 
                    return false;
            }
            
            //Reseting map values
            for (int j=1; j<=matrix.size(); j++) {
                rmap[j] = 0;
                cmap[j] = 0;
            }
        }
        
        return true;
        
    }
};

// Approach: 2, with constant space
class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        
        
        int rows = matrix.size();
        
        if (rows == 0) 
            return true;
        
        int columns = matrix[0].size();
        
        if (rows != columns)
            return false;
        
        // Row wise scan
        for (int i=0; i<rows; i++) {
            for (int j=0; j<columns; j++) {
                int index = abs(matrix[i][j]) - 1;
                if (matrix[i][index] < 0)
                    return false;
                else 
                    matrix[i][index] = -matrix[i][index];
            }     
        }
        
        // Column wise scan
        for (int i=0; i<rows; i++) {
            for (int j=0; j<columns; j++) {
                int index = abs(matrix[j][i])-1;
                if (matrix[index][i] > 0)
                    return false;
                else {
                    matrix[index][i] = -matrix[index][i];
                }
                
            }     
        }
        
        return true;
        
    }
};
