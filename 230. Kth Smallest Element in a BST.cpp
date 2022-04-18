

class Solution {
    
    vector<int> inorder;
    
public:
    int kthSmallest(TreeNode* root, int k) {
        
        // inorderTraversal(root);
        // return inorder[k-1];
        ios::sync_with_stdio(0);
        cin.tie(0);
 
        
        return solve(root, k);
            
    }
    
    void inorderTraversal(TreeNode* root) {
        
        if (root == NULL) return;
        
        inorderTraversal(root->left);
        inorder.push_back(root->val);
        inorderTraversal(root->right);
        
    }
    
    int solve(TreeNode* root, int &k) {
        
        
        if (!root) return 0;
        
        int left = solve(root->left, k);
        
        if (left) return left;
        
        k--;
        
        if (!k) return root->val;
        
        return solve(root->right, k);
        
    }
    
};
