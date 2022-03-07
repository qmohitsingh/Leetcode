//https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

class Solution {
public:
    // Average time : O(logn), Worst Case Time : O(n)  
    bool search(vector<int>& nums, int target) {
        
        int size = nums.size();
        
        int low = 0;
        int high = size - 1;
        
        while(low < high) {
            
            // mid = 0 + (6 - 0)/2 = 3
            int mid = low + (high - low)/2;
            
            if (nums[mid] > nums[high]) 
                low = mid + 1;
            else if (nums[mid] == nums[high])
                high--;
            else 
                high = mid;
        }
        
        // Worst Case : O(n) as it might to iterate whole array
        // This is to handle corner cases like : 
        // [1,0,1,1,1]
        // 0
        // [1,1,2,1]
        // 2
        // [2,2,2,3,2,2,2]
        // 3
        high = size-1;
        while(high >=0 && nums[low] == nums[high]){
            low = high;
            high--;
        }
            
        int start = 0;
        int end = size-1;
        
        if (nums[low]<=target && nums[size-1]>=target) {
            start = low;
        }else {
            end = low-1;
        }
        
        return binarySearch(nums, target, start, end);
    }
    
    
    bool binarySearch(vector<int> &nums, int target, int low, int high) {
        
        while(low < high) {
            
            int mid = low + (high - low)/2;
            
            if (nums[mid] < target) 
                low = mid + 1;
            else 
                high = mid;
        }
        
        return nums[low] == target;
        
    }    
};
