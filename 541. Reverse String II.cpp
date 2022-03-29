//https://leetcode.com/problems/reverse-string-ii/

class Solution {
public:
    string reverseStr(string s, int k) {
        
        int len = s.length();
        
        for ( int i=0; i<len; i+= 2*k) {
            
            int low = i, high = i+k-1 < len ? i+k-1 : len-1;
            
            while(low < high) {
                char ch = s[low];
                s[low] = s[high];
                s[high] = ch;
                low++;
                high--;
            }
        }
        
        return s;
        
    }
};
