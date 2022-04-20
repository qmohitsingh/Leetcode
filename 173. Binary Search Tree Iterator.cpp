//https://leetcode.com/problems/binary-search-tree-iterator/

class BSTIterator {
public:
    stack<TreeNode*> stk;
    
    void push_left(TreeNode* node){
        while(node){
            stk.push(node);
            node = node->left;
        }
    }
    
    BSTIterator(TreeNode* root) {
        //go left
        push_left(root);
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* cur = stk.top(); stk.pop();
        //visit itself
        int val = cur->val;
        //go right
        if(cur->right){
            push_left(cur->right);
        }
        return val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk.empty();
    }
};
