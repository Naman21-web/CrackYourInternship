/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flattennode(Node* root){
        if(root==NULL) return NULL;
        if(!root->child){
            root->next = flattennode(root->next);
            return root;
        }
        Node* head=root;
        Node* temp = root->next;
        root->next = flattennode(root->child);
        root->child->prev= root;
        root->child=NULL;
        while(root->next){
            root = root->next;
        }
        root->next = temp;
        if(temp!=NULL)temp->prev = root;
        return head;
    }
    Node* flatten(Node* head) {
        return flattennode(head);
    }
};