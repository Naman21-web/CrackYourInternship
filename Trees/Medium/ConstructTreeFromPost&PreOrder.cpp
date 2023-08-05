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
    int idx=0;
    int find(vector<int>& postorder,int val){
        for(int i=0;i<postorder.size();i++){
            if(postorder[i]==val) return i;
        }
        return -1;
    }
    TreeNode* constructTree(vector<int>& preorder, vector<int>& postorder,int start,int end,int &ind){
        if(idx==preorder.size()) return NULL;
        if(start>end) return NULL;
        int val = preorder[idx++];
        TreeNode* root = new TreeNode(val);
        int index = find(postorder,val);
        root->left = constructTree(preorder,postorder,start,index-1,ind);
        root->right = constructTree(preorder,postorder,ind+1,index-1,ind);
        ind=index;
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int ind=0;
        int n=preorder.size();
        return constructTree(preorder,postorder,0,n-1,ind);        
    }
};