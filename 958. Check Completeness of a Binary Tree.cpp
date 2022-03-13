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
        int total = countNodes(root);
        return dfs(root, 1, total);
    }
    
    int countNodes(TreeNode* root) {
        
        if (root == NULL) return 0;
        
        return 1 + countNodes(root->left) + 
        countNodes(root->right);
        
    }
    
    bool dfs(TreeNode* root, int current, int size) {
        
        if (root == NULL) return true;
        
        if (current > size)
            return false;
        
        return dfs(root->left, current*2, size) &&
        dfs(root->right, current*2+1, size);
    }
};
