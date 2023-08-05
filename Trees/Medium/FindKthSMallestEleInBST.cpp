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
    // void inorder(TreeNode* root,vector<int> &v){
    //     if(root==NULL) return;
    //     inorder(root->left,v);
    //     v.push_back(root->val);
    //     inorder(root->right,v);
    // }
    void inorder(TreeNode* root,int &currnode,int k,int &ans){
        if(root==NULL) return;
        inorder(root->left,currnode,k,ans);
        currnode++;
        if(currnode==k){
            ans=root->val;
            return;
        }
        inorder(root->right,currnode,k,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        // vector<int> v;
        int ans=0;
        int currnode=0;
        inorder(root,currnode,k,ans);
        return ans;
    }
};