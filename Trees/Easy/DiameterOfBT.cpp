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
    int diameter(TreeNode* root,int &height){
        if(root==NULL) return 0;
        int lh=0,rh=0;
        int leftd = diameter(root->left,lh);
        int rightd = diameter(root->right,rh);
        height = max(lh,rh)+1;
        int currd = lh+rh+1;
        return max({currd,leftd,rightd});
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int height=0;
        return diameter(root,height)-1;
    }
};