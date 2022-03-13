//958. Check Completeness of a Binary Tree

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
    bool isCompleteTree(TreeNode* root) {
        
        if (!root) 
            return true;
        
        queue<TreeNode* > q;
        q.push(root);
        
        bool flag = false;
        while(!q.empty()) {
            
            TreeNode* p = q.front();
            q.pop();
            
            if (p != NULL && flag) return false;
                
            if (p == NULL) {
                flag = true;
                continue;
            }
            
            q.push(p->left);
            q.push(p->right);
            
        }
        
        return true;
        
    }
};
