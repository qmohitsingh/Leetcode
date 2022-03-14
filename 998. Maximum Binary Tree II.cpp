//https://leetcode.com/problems/maximum-binary-tree-ii/

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
    
    void inOrderTraversal(vector<int> & nums, TreeNode* root) {
        if (root == NULL) return;
        
        inOrderTraversal(nums, root->left);
        
        nums.push_back(root->val);
        
        inOrderTraversal(nums, root->right);
        
    }
    
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        
        vector<int> nums;
        
        inOrderTraversal(nums, root);
        nums.push_back(val);
        
        return dfs(nums, 0, nums.size());
        
    }
    
    TreeNode* dfs(vector<int> & nums, int l, int r) {
        
        if (l >= r)
            return NULL;
        
        int index = findMax(nums, l, r);
        
        TreeNode* root = new TreeNode(nums[index]);
        
        root->left = dfs(nums, l, index);
        root->right = dfs(nums, index+1, r);
        
        return root;
    }
    
    int findMax(vector<int> array, int i, int j) {
        
        int maxIndex = i;
        
        for (;i<j; i++) {
            if (array[i] > array[maxIndex])
                maxIndex = i;
        }
        
        return maxIndex;
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
    
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        
        if (root == NULL) {
            TreeNode* temp = new TreeNode(val);
            return temp;
        }
        
        if (root->val < val) {
            TreeNode* temp = new TreeNode(val);
            temp->left = root;
            return temp;
        }
        
        root->right = insertIntoMaxTree(root->right, val);
        
        return root;
        
    }
};
