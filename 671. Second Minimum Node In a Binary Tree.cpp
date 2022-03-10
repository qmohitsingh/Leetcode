//https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        
        set<int> s;
        
        dfs(root, 2, s);
        
        if (s.size() < 2) 
            return -1;
        
        return *next(s.begin(), 1);
        
    }
    
    void dfs(TreeNode* root, int k, set<int>& s) {
        
        if (root == NULL)
            return;
        
        s.insert(root->val);
        
        dfs(root->left, k, s);
        dfs(root->right, k, s);
        
    }
};
