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
    int getSum(TreeNode* root){
        if(!root->left && !root->right){
            return root->val;
        }
        int sum=0;
        if(root->left){
            sum += getSum(root->left);
        }
        if(root->right && (root->right->left || root->right->right)){
            sum += getSum(root->right);
        }
        return sum;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root->left && !root->right){
            return 0;
        }
        return getSum(root);
    }
};