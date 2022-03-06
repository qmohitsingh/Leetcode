//https://leetcode.com/problems/search-in-rotated-sorted-array/


class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int size = nums.size();
        
        int low = 0;
        int high = size - 1;
        
        while(low < high) {
            int mid = low + (high - low)/2;
            
            if(nums[mid] > nums[high]) 
                low = mid + 1;
            else 
                high = mid;
        }
        
        int left  = binarySearch(nums, target, 0, low-1);
        int right = binarySearch(nums, target, low, size-1);
        
        return left != -1 ? left : right;
        
    }
    
    
    int binarySearch(vector<int>& nums, int target, int low, int high) {
        
        while(low < high) {
            int mid = low + (high-low)/2;
            
            if (nums[mid] < target ) low = mid + 1;
            else high = mid;
        }
        
        return nums[low] == target ? low : -1;
        
    }
};
