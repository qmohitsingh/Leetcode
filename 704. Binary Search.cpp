//https://leetcode.com/problems/binary-search/submissions/


// Variation : 1

class Solution {
    
    // Case 1: nums = [1 2 3 4 5 6 7 8 9], target = 6 
    public int search(int[] nums, int target) {
        
        int size = nums.length;
        
        int low = 0;
        int high= size-1;
        
        // Iteration - 1 : low = 0, high = 8 , size = 9
        // Iteration - 2 : low = 5, high = 8 , size = 9
        // Iteration - 3 : low = 5, high = 5 , size = 9 ←
        while(low <= high) {
            
            // Iteration - 1 : mid = 0 + (8-0)/2 = 4
	          // iteration - 2 : mid = 5 + (8-5)/2 = 6
            // iteration - 2 : mid = 5 + (5-5)/2 = 5
            int mid = low + (high-low)/2;
            
            // Iteration - 1 : nums[4] = 5, target 6
            // Iteration - 1 : nums[6] = 7, target 6
            // Iteration - 1 : nums[5] = 6, target 6
            if(nums[mid] == target) return mid;
            else if (nums[mid] > target) high = mid-1;
            else low = mid+1;
        }
        
        return -1;
        
    }
}


// Variation : 2

class Solution {
    
    // Case 1: nums = [1 2 3 4 5 6 7 8 9], target = 6 
    public int search(int[] nums, int target) {
        
        int size = nums.length;
        
        int low = 0;
        int high= size-1;
        
        // Iteration - 1 : low = 0, high = 8 , size = 9
        // Iteration - 2 : low = 5, high = 8 , size = 9
        // Iteration - 3 : low = 5, high = 6 , size = 9 ←
        while(low < high) {
            
            // Iteration - 1 : mid = 0 + (8-0)/2 = 4
	        // iteration - 2 : mid = 5 + (8-5)/2 = 6
            // iteration - 2 : mid = 5 + (5-5)/2 = 5
            int mid = low + (high-low)/2;
            
            // Iteration - 1 : nums[4] = 5, target 6
            // Iteration - 1 : nums[6] = 7, target 6
            // Iteration - 1 : nums[5] = 6, target 6
            if (nums[mid] < target) low = mid+1;
            else high = mid;
        }
        
        return nums[low] == target ? low : -1;
        
    }
}
