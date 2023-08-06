class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    Node* prev=NULL;
    Node* ans = new Node(-1);
    void inorder(Node* root){
        if(root==NULL) return;
        inorder(root->left);
        root->left=prev;
        // if(prev==NULL) ans=root;
        prev=root;
        inorder(root->right);
    }
    Node * bToDLL(Node *root)
    {
        // your code here
        if(root==NULL) return NULL;
        inorder(root);
        Node* next=NULL;
        while(prev->left) {prev->right=next;next=prev;prev=prev->left;}
        return prev;
    }
};