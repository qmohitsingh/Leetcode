//https://leetcode.com/problems/combination-sum-iv/

class Solution {
public:
    int ans = 0;
    
    vector<vector<int>> cache;
    int combinationSum4(vector<int>& nums, int target) {
        
        cache = vector<vector<int>>(1001,vector<int>(1001, -1));
        
        sort(nums.begin(), nums.end());
        
        return dfs(nums, 0, target);
        
    }
    
    int dfs(vector<int>& nums, int index, int target){
        
        
        if (target < 0 || index >= nums.size())
            return 0;
        
        if (target == 0)
            return 1;
        
        if (cache[index][target] != -1)
            return cache[index][target];
       
        int take = dfs(nums, 0, target-nums[index]);
        int skip = dfs(nums, index+1, target);
        
        return cache[index][target] = take + skip;
        
    }
};
