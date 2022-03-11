//https://leetcode.com/problems/squares-of-a-sorted-array/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int size = nums.size();
        
        int low = 0, high = size-1;
        
        vector<int> ans(size);
        
        int pointer = size-1;
        for (int i=0; i<nums.size(); i++) {
            nums[i] = nums[i]*nums[i]; 
        }
        
        while(low <= high && pointer >= 0) {
            if (nums[high] >= nums[low] ){
                ans[pointer--] = nums[high];
                high--;
            } else{
                ans[pointer--] = nums[low];
                low++;
            }
        }
        
        return ans;
        
    }
};

