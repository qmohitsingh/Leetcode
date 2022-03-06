//https://leetcode.com/problems/minimum-depth-of-binary-tree/

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
    
//     //BFS Approach
//     int minDepth(TreeNode* root) {
        
//         if (root == NULL) 
//             return 0;
        
//         queue<pair<TreeNode*,int>> pq;
//         pq.push({root, 1});
        
//         while(!pq.empty()) {
            
//             pair<TreeNode*, int> temp =  pq.front();
            
//             pq.pop();
            
//             if (temp.first->left == NULL && temp.first->right == NULL)
//                 return temp.second;
            
//             if (temp.first->left != NULL)
//                 pq.push({temp.first->left, temp.second+1});
            
//             if (temp.first->right != NULL)
//                 pq.push({temp.first->right, temp.second+1});
            
//         }
        
//         return 0;
//     }
    
    //DFS Approach
    int minDepth(TreeNode* root) {
        
        int ans = INT_MAX;
        
        dfs(root, 1, ans);
        
        return ans == INT_MAX ? 0 : ans;
    }
    
    void dfs(TreeNode* root, int level, int& ans) {
        
        if (root == NULL)
            return;
        
        if (root->left == NULL && root->right == NULL)
            ans = min(ans, level);
        
        dfs(root->left, level+1, ans);
        dfs(root->right, level+1, ans);
        
        
    }
};
