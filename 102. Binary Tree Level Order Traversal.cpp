//https://leetcode.com/problems/binary-tree-level-order-traversal/submissions/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        // This will store the answer
        vector<vector<int>> result;
        
        if (root == NULL) 
            return result;
        
        // Standard BFS algo
        queue<pair<int, TreeNode*>> pq;
        pq.push({0, root});
        
        // Store the nodes level-wise
        unordered_map<int, vector<int>> map;
        
        while(!pq.empty()) {
            pair<int, TreeNode*> temp = pq.front();
            pq.pop();
            
            if (temp.second->left != NULL) pq.push({temp.first+1, temp.second->left});
            if (temp.second->right != NULL) pq.push({temp.first+1, temp.second->right});
            
            map[temp.first].push_back(temp.second->val);
        }
    
        // Populating nodes in results from map based on level
        for (int i=0; i<map.size(); i++) {
            result.push_back(map[i]);
        }
        
        
        return result;
    }
};
