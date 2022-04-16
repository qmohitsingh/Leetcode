//https://leetcode.com/problems/convert-bst-to-greater-tree/


class Solution {
public:
    int sum  = 0;
    TreeNode* convertBST(TreeNode* root) {
        if (root == nullptr)
            return root;
        convertBST(root->right);
        sum += root->val;
        root->val = sum;
        convertBST(root->left);
        return root;
    }
};
