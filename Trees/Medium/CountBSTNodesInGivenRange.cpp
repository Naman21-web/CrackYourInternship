void count(Node* root,int l,int h,int &ans){
        if(root==NULL) return;
        if(root->data<=h && root->data>=l) ans++;
        count(root->left,l,h,ans);
        count(root->right,l,h,ans);
    }
    int getCount(Node *root, int l, int h)
    {
      // your code goes here  
      int ans=0;
      count(root,l,h,ans);
      return ans;
    }