//https://leetcode.com/problems/average-of-levels-in-binary-tree/

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
    
    vector<double> averageOfLevels(TreeNode* root) {

        vector<double> avgs;
        vector<double> counts;
        
        dfs(root, 0, avgs, counts);
        
        for(int i=0; i<avgs.size(); i++) {
            avgs[i] = avgs[i]/counts[i];
        }
            
        return avgs;
        
    }
    
    void dfs(TreeNode* root, int level, vector<double>& avgs, vector<double>& counts) {
        
        if (root == NULL)
            return;
        
        if(avgs.size() == level)
            avgs.push_back({});
        
        if (counts.size() == level)
            counts.push_back({});
        
        counts[level] += 1;
        avgs[level]   += root->val;
        
        dfs(root->left,  level+1, avgs, counts);
        dfs(root->right, level+1, avgs, counts);
    }
};
