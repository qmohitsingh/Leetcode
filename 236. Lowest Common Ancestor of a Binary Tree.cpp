//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Time: O(n), Space: O(n)
class Solution {
public:
    
    unordered_map<TreeNode*, TreeNode*> map;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        dfs(root, NULL);
        
        while(map[p] != NULL) {
            
            TreeNode* temp = map[p];
            map[p] = NULL;
            p = temp;
            
        }
        
        while(map[q] != NULL) {
            
            TreeNode* temp = map[q];
            map[p] = NULL;
            q = temp;
            
        }
        
        return q;
    }
    
    void dfs(TreeNode* root, TreeNode* parent) {
        
        if (root == NULL)
            return;
        
        map[root] = parent;
        
        dfs(root->left,  root);
        dfs(root->right, root);
        
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Time: O(n), Space: O(1)
class Solution {
public:
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        return dfs(root, p, q);
    }
    
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if (root == NULL || root == p || root == q)
            return root;
        
        TreeNode* left = dfs(root->left,  p, q);
        TreeNode* right = dfs(root->right, p, q);
        
        if (left && right)
            return root;
        
        return left ? left : right;
        
    }
};
