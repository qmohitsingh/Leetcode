//https://leetcode.com/problems/combination-sum-iii/


// Recursion
class Solution {
public:
    
    vector<vector<int>> ans;
    vector<int> vec;
    int size;
    vector<vector<int>> combinationSum3(int k, int n) {
        size = k;
        dfs(0,1,n);
        return ans;
    }
    
    
    void dfs(int sum, int index, int n) {
        
        if (sum > n || vec.size() > size) return;
        
        if (sum == n && vec.size() == size) {
            ans.push_back(vec);
            return;
        }
        
        for (int i=index; i<=9; i++) {
            vec.push_back(i);
            dfs(sum+i, i+1, n);
            vec.pop_back();
        }
    }
    
};
