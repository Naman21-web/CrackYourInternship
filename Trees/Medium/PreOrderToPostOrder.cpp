public:
    //Function that constructs BST from its preorder traversal.
    Node* solve(int pre[], int& i, int bound, int n){
        if(i==n || pre[i] > bound){
            return NULL;
        }
        int x= pre[i];
        Node* root = newNode(x);
        i++;
        root->left = solve(pre, i, root->data, n);
        root->right = solve(pre, i, bound, n);
        return root;
    }
    Node* post_order(int pre[], int size)
    {
        int i=0;
        Node* root= solve(pre, i, INT_MAX, size);
        return root;
    }
};