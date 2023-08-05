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
    int calcsum(TreeNode* root,int &sum){
        if(root==NULL) return 0;
        int ls = max(0,calcsum(root->left,sum));//If I get the leftsum as less than 0 so we will not consider that sum as it will only decrese my resultant sum and I want max sum

        int rs = max(0,calcsum(root->right,sum));//similary If I get the rightsum as less than 0 so we will not consider that sum as it will only decrese my resultant sum and I want max sum

        sum = max(sum,ls+rs+root->val);//this is the diameter sum including leftnode,rightnode and current node //so this is max sum because it will handle all cases of max that is 
        //1-> when left sum is from left or right tree then that sum will automatically be considered in sum when we call this func for left or right subtree
        //2-> when leftsum or rightsum is -ve that case will automatically be handled because we take max(0,ls) so if ls -ve 0 is taken and it will not be added in my sum

        return root->val + max(ls,rs);//At last returning max sum from left or right subtree
    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL) return 0;
        if(!root->left && !root->right) return root->val;
        int sum=INT_MIN;
        int rootsum = calcsum(root,sum);
        return sum;
    }
};