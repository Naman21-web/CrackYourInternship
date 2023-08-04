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
    
    int height(TreeNode *root, bool &ans)
    {
        if(root == NULL)
            return 0;
        
        int lheight = height(root->left, ans);
        int rheight = height(root->right, ans);
        ans = ans && abs(lheight - rheight) <= 1;
        
        return max(lheight, rheight) + 1;
    }
    
    bool isBalanced(TreeNode* root) 
    {
        bool ans = true;
        height(root, ans);
        return ans;
    }
};