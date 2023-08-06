struct Info{
    int size;
    int max;
    int min;
    int BSTsize;
    bool isBST;
};

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    Info getLargestBST(Node* root){
        if(root==NULL) return {0,INT_MIN,INT_MAX,0,true};
        Info leftTree = getLargestBST(root->left);
        Info rightTree = getLargestBST(root->right);
        Info ans;
        if(leftTree.max<root->data && rightTree.min>root->data && leftTree.isBST && rightTree.isBST){
            ans.size = leftTree.size+rightTree.size+1;
            ans.max = max({rightTree.max,root->data,leftTree.max});
            ans.min = min({leftTree.min,root->data,rightTree.min});
            ans.BSTsize = leftTree.BSTsize + rightTree.BSTsize + 1;
            ans.isBST = true;
            return ans;
        }
        else{
           ans.size = leftTree.size+rightTree.size+1;
           ans.max = max({rightTree.max,root->data,leftTree.max});
           ans.min = min({leftTree.min,root->data,rightTree.min});
           ans.BSTsize = max(leftTree.BSTsize,rightTree.BSTsize);
           ans.isBST = false;
           return ans;
        }
    }
    int largestBst(Node *root)
    {
    	//Your code here
    	Info ans = getLargestBST(root);
    	return ans.BSTsize;
    }
};