//https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    
    //Time - O(n), Space - O(n) - Sliding window approach
    int lengthOfLongestSubstring(string s) {
        
        int ans = 0;
        
        int size = s.length();
        
        int low = 0;
        int high = 0;
        
       unordered_map<char, int> map;     
        
        while (low <= high && high < size) {
            
            map[s[high]]++;
            
            while(map[s[high]] > 1) {
                map[s[low]]--;
                low++;
            }
            
            ans = max(ans, high - low + 1);
            high++;
            
        }
        
        return ans;
        
    }
};


// Naive Solution;
//     Step 1 : Pick first letter
//     Step 2 : keep going untill you encounter the repititive char & also keep track of length
//     Step 3 : update maxLength so far
//     Step 4 : Pick next letter and repeat above steps
    
//     Time: O(n^2), Space: O(1);

// Sliding window: It has two pointers
