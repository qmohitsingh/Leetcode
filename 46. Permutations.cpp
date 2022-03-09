//https://leetcode.com/problems/permutations/submissions/


class Solution {
public:
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        unordered_map<int,int> map;
        
        permuteHelper(nums, vector<int>(), ans, map);
        
        return ans;
    }
    
    
    void permuteHelper(vector<int>& nums, vector<int> temp, vector<vector<int>>& ans, unordered_map<int,int>& map) {
        
        if (temp.size () > nums.size()) return;
        
        if (temp.size () == nums.size()) {
            ans.push_back(temp);
            return;
        }
        
        for (int i=0; i<nums.size(); i++) {
            
            if (map[nums[i]] != 1) {
                map[nums[i]] = 1;
                temp.push_back(nums[i]);
                permuteHelper(nums, temp, ans, map);
                temp.pop_back();
                map[nums[i]] = 0;
            }
        }
    }
};
