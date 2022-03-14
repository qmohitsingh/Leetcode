//https://leetcode.com/problems/combination-sum/

class Solution {
public:

    vector<int> temp;
    vector<vector<int>> ans;

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        
        dfs(nums, target, 0);
        
        return ans;
    }
    
    
    void dfs(vector<int>& nums, int target, int index) {
        
        if (target < 0) return;
        
        if (target == 0) {
            ans.push_back(temp);
        }
        
        for (int i=index; i<nums.size(); i++) {
            
            temp.push_back(nums[i]);
            dfs(nums, target-nums[i], i);
            temp.pop_back();
        }
        
    }
};
