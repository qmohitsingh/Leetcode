//https://leetcode.com/problems/copy-list-with-random-pointer/submissions/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        Node* headCopy1 = head;
        Node* headCopy2 = head;
        
        Node* root = new Node(-1);
        Node* dummy = root;
        
        unordered_map<Node*, Node*> map;
        
         // Adding next pointer and values
        while(headCopy1 != NULL) {
            
            Node* temp = new Node(headCopy1->val);
            temp->next = headCopy1->next;
            temp->random = NULL;
            
            map[headCopy1] = temp;
            
            dummy->next = temp;
            dummy = dummy->next;
            
            headCopy1 = headCopy1->next;
        }
        
        
        dummy = root->next;
        
        // Adding random pointer
        while(headCopy2 != NULL) {
            
            dummy->random = map[headCopy2->random];
            dummy = dummy->next;
            
            headCopy2 = headCopy2->next;
        }
        
        return root->next;
    }
};


// After Refactoring the code : 

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        Node* dummy = head;
        
        unordered_map<Node*, Node*> map;
        
        // Step-1 : Copy the original list;
        while(dummy != NULL) {
            map[dummy] = new Node(dummy->val);
            dummy = dummy->next;
        }
        
        
        dummy = head;
        
        // Step-2 : Add pointers (next & random ones);
        while(dummy != NULL) {
            
            map[dummy]->next = map[dummy->next];
            map[dummy]->random = map[dummy->random];
            
            dummy = dummy->next;
        }
        
        return map[head];
    }
};
