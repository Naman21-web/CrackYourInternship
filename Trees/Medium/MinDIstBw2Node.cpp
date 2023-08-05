Node* findLCA(Node* root,int a,int b){
        if(root==NULL) return NULL;
        if(root->data==a || root->data==b) return root;
        Node* leftans = findLCA(root->left,a,b);
        Node* rightans = findLCA(root->right,a,b);
        if(leftans && rightans) return root;
        if(!leftans && !rightans) return NULL;
        if(leftans) return leftans;
        return rightans;
    }
    int calcdist(Node* root,int num){
        if(root==NULL) return 1e9;
        if(root->data==num) return 0;
        int ans=INT_MAX;
        ans = min(ans,1+calcdist(root->left,num));
        ans = min(ans,1+calcdist(root->right,num));
        return ans;
    }
    int findDist(Node* root, int a, int b) {
        // Your code here
        Node* lca = findLCA(root,a,b);
        int x = calcdist(lca,a);
        int y = calcdist(lca,b);
        return x+y;
    }