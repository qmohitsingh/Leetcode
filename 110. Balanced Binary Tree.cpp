//https://leetcode.com/problems/balanced-binary-tree/

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
    bool isBalanced(TreeNode* root) {
        
        if (root == NULL) 
            return true;
        
        return isBalanced(root->left) 
            && isBalanced(root->right) 
            && abs(getHeight(root->left) - getHeight(root->right)) <= 1;
    }
    
    int getHeight(TreeNode* root) {
        
        if (root == NULL)
            return 0;
        
        int h =  max(getHeight(root->left), getHeight(root->right)) + 1;
        
        return h;
    }
    
};
