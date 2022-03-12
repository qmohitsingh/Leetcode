//https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     
        int size = nums.size();
        int low = 0; 
        int high = size-1;
        
        vector<int> ans;
        while(low < high) {
            if (nums[low] + nums[high] == target){
                ans.push_back(low+1), 
                ans.push_back(high+1);
                break;
            }
                
            else if (nums[low] + nums[high] > target) 
                high--;
            else
                low++;
        }
        
        return ans;
    }
    
};
