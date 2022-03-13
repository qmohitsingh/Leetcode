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
    
    // Time Complexity : O(n), Space Complexity : O(n) [Stack Size]
    TreeNode* pruneTree(TreeNode* root) {
        
        if (root == NULL)
            return root;
        
        TreeNode* left = pruneTree(root->left);  
        TreeNode* right= pruneTree(root->right); 
        
        // Reassigning the left & right subtrees of the root
        root->left = left;
        root->right= right;
        
        // This is condition that cracks this question, which is mentioned in the question
        if (!left && !right && !root->val)
            root = NULL;
        
        return root;
        
    }
};

Complexity Analysis

Time Complexity: O(N)O(N), where NN is the number of nodes in the tree. We process each node once.

Space Complexity: O(N)O(N), the recursion call stack can be as large as the height HH of the tree. In the worst case scenario, H=NH=N, when the tree is skewed.

