//https://leetcode.com/problems/matrix-cells-in-distance-order/

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
     
        set<pair<int, pair<int,int>>> s;
        
        vector<vector<int>> ans;
        
        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                int dist = abs(i-rCenter) + abs(j-cCenter);
                
                s.insert({dist, {i,j}});
            }
        }
        
        // set<pair<int, pair<int,int>>>::iterator it;
        for (auto it = s.begin(); it != s.end(); ++it)  {
            vector<int> temp;
            
            //temp.push_back(*it.second.first);
            pair<int, pair<int,int>> pair = *it;
            temp.push_back(pair.second.first);
            temp.push_back(pair.second.second);
            
            ans.push_back(temp);
        }

        
        return ans;
    }
};
