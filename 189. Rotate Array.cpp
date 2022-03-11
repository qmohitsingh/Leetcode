//https://leetcode.com/problems/rotate-array/

class Solution {
public:
//     void rotate(vector<int>& nums, int k) {
        
//         vector<int> ans;
        
//         int size = nums.size();
        
//         k = k%size;
        
//         for(int i=size-k; i<size; i++) 
//             ans.push_back(nums[i]);
        
//         for(int i=0; i<size-k; i++)
//             ans.push_back(nums[i]);
        
//         nums = ans;
//     }
    
    void rotate(vector<int>& nums, int k) {
        
        int size = nums.size();
        
        k = k%size;
        
        if (!k) return;
        
        int low = size - k, high = size - 1;
        
        while(low<high) {
            int t = nums[low];
            nums[low] = nums[high];
            nums[high] = t;
            low++;
            high--;
        }
        
        low = 0, high = size - k - 1;
        
        while(low<high) {
            int t = nums[low];
            nums[low] = nums[high];
            nums[high] = t;
            low++;
            high--;
        }
        
        low = 0, high = size - 1;
        
        while(low<high) {
            int t = nums[low];
            nums[low] = nums[high];
            nums[high] = t;
            low++;
            high--;
        }
    }
};

// [1,2,3,4,5,6,7];

// [4,3,2,1,7,6,5];

// [5,2,3,4,1,6,7];
// [5,6,3,4,1,2,7];
// [5,2,7,4,1,2,3];



// [1,2,3,4,5];
// [5,1,2,3,4];
// [4,5,1,2,3];
// [3,4,5,1,2];
// [2,3,4,5,1];
// [1,2,3,4,5];
