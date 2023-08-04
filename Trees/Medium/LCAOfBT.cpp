/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        if(root==p || root==q) return root;
        TreeNode* inleft = lowestCommonAncestor(root->left,p,q);
        TreeNode* inright = lowestCommonAncestor(root->right,p,q);
        if(inleft && inright) return root;
        if(!inleft && !inright) return NULL;
        if(inleft) return inleft;
        return inright;
    }
};