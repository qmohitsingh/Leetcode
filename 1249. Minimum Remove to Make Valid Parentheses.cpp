//https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/


class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        stack<pair<char, int>> stk;
        
        string ans;
        vector<int> map(s.length(), 0);
        for(int i=0; i<s.length(); i++) {
            
            if (s[i] != '(' && s[i] != ')') continue;
            
            if (!stk.empty() && stk.top().first == '(' && s[i] == ')') {
                stk.pop();
                continue;
            }
            
            stk.push({s[i], i});
        }
        
        while(!stk.empty()) {
            map[stk.top().second] = 1;
            stk.pop();
        }
        
        
        for (int i=0; i<s.length(); i++)
            if (!map[i]) ans += s[i];
        
        return ans;
    }
};
