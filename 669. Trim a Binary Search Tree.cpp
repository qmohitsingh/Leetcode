//https://leetcode.com/problems/trim-a-binary-search-tree/


class Solution {
public:
    
    TreeNode* helper(TreeNode* root, int low, int high) {
        
        if (root == nullptr) return root;
        
        if (root->val > high)
            return helper(root->left, low, high);
        if (root->val < low)
            return helper(root->right, low, high);
        
        root->left  = helper(root->left, low, high);
        root->right = helper(root->right, low, high);
        
        return root;
        
    }
    
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        
        return helper(root, low, high);
    
    }
};
