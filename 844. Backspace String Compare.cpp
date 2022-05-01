//https://leetcode.com/problems/backspace-string-compare/


class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        stack<char> st1, st2;
        
        for (auto ch : s) {
            
            if (ch == '#' && !st1.empty()) {
                st1.pop();
                continue;
            }
            
            if (ch != '#')
                st1.push(ch);
            
        }
        
        for (auto ch : t) {
            
            if (ch == '#' && !st2.empty()) {
                st2.pop();
                continue;
            }
            
            if (ch != '#')
                st2.push(ch);
            
        }
        
        return st1 == st2;
        
    }
};
