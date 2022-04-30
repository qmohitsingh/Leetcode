//https://leetcode.com/problems/valid-palindrome-ii/


class Solution {
public:
    
    bool helper(string s, int low, int high) {
        while(low < high) {
            
            if (s[low] != s[high]) {
                return false;
            }
            low++; 
            high--;
        }
        
        return true;
    }
    
    bool validPalindrome(string s) {
        
        int low = 0, high = s.length()-1;
        
        while(low < high) {
            
            if (s[low] != s[high]) {
                break;
            }
            low++; 
            high--;
        }
        
        return helper(s, low+1, high) || helper(s, low, high-1);
        
    }

    
};
