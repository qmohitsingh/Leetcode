//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/submissions/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        
        vector<int> ans;
        int size = nums.size();
        
        if (size == 0) 
            return {-1,-1};
        
        int first = binarySearchFirst(nums, 0, size-1, target);
        int last  = binarySearchLast(nums, first, size-1, target);
        
        ans.push_back(first);
        ans.push_back(last);
        
        return ans;
        
    }
    
    // Round Down Approach
    int binarySearchFirst(vector<int>& nums, int low, int high, int target) {
        
        while(low < high) {
            int mid = low + (high - low)/2; // Round Down Approach
            
            if(nums[mid] < target) low = low + 1;
            else high = mid;
        }
        
        return nums[low] == target ? low : - 1;
    }
    
    // Round Up Approach
    int binarySearchLast(vector<int>& nums, int low, int high, int target) {
        
        while(low < high) {
            
            int mid = low + (high-low + 1)/2; // Round Up Approach
            
            if(nums[mid] <= target) low = mid;
            else high = mid-1;
        }
        
        return low != -1 && nums[low] == target ? low : - 1;
    }
};
