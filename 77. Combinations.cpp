//https://leetcode.com/problems/combinations/


class Solution {
public:
    
    vector<int> temp;
    vector<vector<int>> ans;
    vector<vector<int>> combine(int n, int k) {
        dfs(n,k,1);
        return ans;
    }
    
    void dfs(int n, int k, int index) {
        
        if (!k) {
            ans.push_back(temp);
            return;
        }
        
        for (int i=index; i<=n; i++) {
            temp.push_back(i);
            dfs(n, k-1, i+1); 
            temp.pop_back();
        }
    }
};
