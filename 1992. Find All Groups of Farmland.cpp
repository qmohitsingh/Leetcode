//https://leetcode.com/problems/find-all-groups-of-farmland/

class Solution {
public:
    
    vector<vector<int>> ans;
    unordered_map<string, int> map;
    
    void dfs(vector<vector<int>>& land, int i, int j, int rows, int cols, int& bi, int& bj) {
        
        
        if (i < 0 || j < 0 || i >= rows|| j >= cols || land[i][j] != 1){
            return;
        }
        
        if (bi < i || bj < j) {
            bi = i;
            bj = j;
        }
        
        //cout<<i<<" "<<j<<" "<<bi<<" "<<bj<<endl;
         
        
        land[i][j] = 0;
        
        dfs(land, i+1, j, rows, cols, bi, bj);
        dfs(land, i-1, j, rows, cols, bi, bj);
        dfs(land, i, j+1, rows, cols, bi, bj);
        dfs(land, i, j-1, rows, cols, bi, bj);
        
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        
        int rows = land.size();
        int cols = land[0].size();
        
        int bi, bj;
        for (int i=0; i<rows; i++)
            for (int j=0; j<cols; j++) {
                
                if(land[i][j]) {
                    bi = i, bj = j;
                    dfs(land, i, j, rows, cols, bi, bj);
                    
                    vector<int> temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    temp.push_back(bi);
                    temp.push_back(bj);

                    ans.push_back(temp);
                }
                
                
            }
        
        return ans;
    }
};

// 0,0 | 0,1 | 1,0, | 1 1
