//https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

class Solution {
public:
    int minAddToMakeValid(string s) {
        
        int ans = 0;
        
        int count = 0;
        for (auto ch : s)
            if (ch == '(')
                count++;
            else if(ch == ')' && count > 0)
                count--;
            else 
                ans++;
        
        count = 0;
        for (int i=s.lengath()-1; i>=0; i--)
            if (s[i] == ')')
                count++;
            else if (s[i] == '(' && count > 0)
                count--;
            else 
                ans++;
    
        
        return ans;
    }
};
