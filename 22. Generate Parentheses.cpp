//https://leetcode.com/problems/generate-parentheses/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        
        vector<string> ans;
        
        dfs(ans, n, n, "");
        
        return ans;
        
    }
    
    void dfs(vector<string>& ans, int left, int right, string str) {
        
        if (left < 0 || left > right) return;
        
        if (!left && !right) {
            ans.push_back(str);
            return;
        }
        
        dfs(ans, left-1, right, str+'(');
        dfs(ans, left, right-1, str+')');
        
    }
};
