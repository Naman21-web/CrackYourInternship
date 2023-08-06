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
    int preorderidx=0;
    TreeNode* constructBST(vector<int> &preorder,int n,int min,int max){
        if(preorderidx>=n) return NULL;
        int value = preorder[preorderidx];
        TreeNode* root=NULL;
        if(value>min && value<max){
            preorderidx++;
            root = new TreeNode(value);
            root->left = constructBST(preorder,n,min,value);
            root->right = constructBST(preorder,n,value,max);
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        return constructBST(preorder,n,INT_MIN,INT_MAX);
    }
};