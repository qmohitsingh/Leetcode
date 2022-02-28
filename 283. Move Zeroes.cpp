//https://leetcode.com/problems/move-zeroes/submissions/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int size = nums.size();
        
        if (size < 2) return;
        
        int low  = 0;
        
        for (int i=0; i<size; i++) {
            
            if (nums[i] == 0) 
                continue;
            
            nums[low++] = nums[i];
        }
        
        for (int i=low; i<size; i++)
            nums[i]=0;
        
    }
};
