//https://leetcode.com/problems/maximum-binary-tree/

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        int size = nums.size();
        
        return dfs(nums, 0, size-1);
    }
    
    
    TreeNode* dfs(vector<int>& nums,int i, int j) {
        
        if (i>j)
            return NULL;
        
        int maxIndex = findMaxIndex(nums, i, j);
        
        TreeNode* root = new TreeNode(nums[maxIndex]);
        
        TreeNode* left = dfs(nums, i, maxIndex-1);
        TreeNode* right= dfs(nums, maxIndex+1, j);
        
        root->left = left;
        root->right = right;
        
        
        return root;
        
    }
    
    int findMaxIndex(vector<int>& nums, int i, int j) {
        
        int index = i;
        
        for(int k=i; k<=j; k++) {
            if (nums[index] < nums[k] ) {
                index = k;
            }
        }
        
        return index;
    }
};


Complexity Analysis

Time complexity : O(n^2)O(n 
2
 ). The function construct is called nn times. At each level of the recursive tree, we traverse over all the nn elements to find the maximum element. In the average case, there will be a \log nlogn levels leading to a complexity of O\big(n\log n\big)O(nlogn). In the worst case, the depth of the recursive tree can grow upto nn, which happens in the case of a sorted numsnums array, giving a complexity of O(n^2)O(n 
2
 ).

Space complexity : O(n)O(n). The size of the setset can grow upto nn in the worst case. In the average case, the size will be \log nlogn for nn elements in numsnums, giving an average case complexity of O(\log n)O(logn)
