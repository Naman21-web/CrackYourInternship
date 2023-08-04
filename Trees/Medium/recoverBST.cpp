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
    TreeNode* first=NULL;
    TreeNode* mid=NULL;
    TreeNode* last=NULL;
    TreeNode* prev=NULL;
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        // if(prev) cout<<prev->val;
        // cout<<root->val<<" ";
        if(prev!=NULL && root->val<prev->val){
            if(first==NULL){
                first = prev;
                mid = root;
            }
            else last=root;
        }
        prev=root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        if(last){
            // cout<<first->val<<last->val;
            int temp = first->val;
            first->val = last->val;
            last->val = temp;
        }
        else {
            // cout<<first->val<<mid->val;
            int temp = first->val;
            first->val = mid->val;
            mid->val = temp;
        }
    }
};