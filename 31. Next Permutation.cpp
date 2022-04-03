//https://leetcode.com/problems/next-permutation/
//Reference : https://www.nayuki.io/page/next-lexicographical-permutation-algorithm

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int size = nums.size();
        
        int largest = size - 1;
        
        while(largest > 0 && nums[largest-1] >= nums[largest] ) 
            largest--;
        
        if (largest <= 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        int pivot = largest - 1;
        
        int high = size - 1;
        while(nums[high] <= nums[pivot]) 
            high--;
        
        int c = nums[high];
        nums[high] = nums[pivot];
        nums[pivot] = c;
        
        reverse(nums.begin() + pivot + 1, nums.end());
        
    }
};
