//https://leetcode.com/problems/previous-permutation-with-one-swap/

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        
        int size = arr.size();
        
        // rms = right most smallest element
        int rms = size - 1;
        
        while(rms > 0 && arr[rms] >= arr[rms-1]) 
            rms--;
        
        if (rms <= 0) return arr;
        
        int pivot = rms - 1;
        
        int high = size - 1;
        while(arr[high] >= arr[pivot] || arr[high - 1] == arr[high]) 
            high--;
        
        int c = arr[high];
        arr[high] = arr[pivot];
        arr[pivot] = c;
        
        //reverse(arr.begin()+pivot+1, arr.end());
        
        return arr;
    }
};
