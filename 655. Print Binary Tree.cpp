//https://leetcode.com/problems/print-binary-tree/

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
    
    int h=0;
    
    int getHeight(TreeNode* root){
        if (root == NULL)
            return 0;
        
        return max(getHeight(root->left), getHeight(root->right)) + 1;
    }
    
    void dfs(TreeNode* root, vector<vector<string>>& matrix, int l, int r, int h) {
        
        if (root == NULL)
            return;
        
        int mid = (l+r)/2;
        
        matrix[h][mid] = to_string(root->val);
        
        dfs(root->left, matrix, l, mid-1, h+1);
        dfs(root->right, matrix, mid+1, r, h+1);
        
    }
    
    vector<vector<string>> printTree(TreeNode* root) {
        
        int h = getHeight(root);
        int cols = pow(2, h) - 1;
        
        vector<vector<string>> matrix(h, vector<string>(cols));
        
        dfs(root, matrix, 0, cols-1, 0);
        
        return matrix;
    }
    
    
};
