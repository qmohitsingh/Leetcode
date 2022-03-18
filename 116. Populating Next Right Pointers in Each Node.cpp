//https://leetcode.com/problems/populating-next-right-pointers-in-each-node/


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    Node* connect(Node* root) {
        
        if (root == nullptr) return root;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            
            int size = q.size();
            
            Node* prev = NULL;
            for (int i=0; i<size; i++) {
                
                Node* current = q.front();
                q.pop();
                
                if (prev)
                    prev->next = current;
                
                prev = current;
                
                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
            }   
        }
        
        return root;
    }
    
};


// DFS Approach

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    Node* connect(Node* root) {
        
        if (root == nullptr) return root;
        
        if (root->left)
            root->left->next = root->right;
        if (root->left && root->next)
            root->right->next = root->next->left;
        
        connect(root->left);
        connect(root->right);
        
        return root;
            
        
    }

    
};
