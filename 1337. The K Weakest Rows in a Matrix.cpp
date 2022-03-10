//https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        vector<int> ans;
        
        int row = mat.size();
        int column = mat[0].size();
        
        // S - O(row)
        vector<pair<int,int>> map(row);
        
        // T - O(row*column)
        for (int i=0; i<row; i++) {
            for (int j=0; j<column; j++) {
                map[i] = {map[i].first+mat[i][j], i};
            }
        }
        
        // T - O(rowlogrow) sorting
        sort(map.begin(), map.end());
        
        for (int i=0; i<k; i++) {
            ans.push_back(map[i].second);
        }
        
        return ans;
    }
    
    
    int binarySearch(vector<int>& nums) {
        int low = 0;
        int high = nums.size();
        
        while(low < high) {
            int mid = low + (high - low)/2;
            
            if (nums[mid] > nums[high]) 
                low = mid + 1;
            else high = mid;
        }
        
        cout<<low<<endl;
        
        return low;
    }
};
