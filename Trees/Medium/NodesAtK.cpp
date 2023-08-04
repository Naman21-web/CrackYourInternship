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
    vector<int> ans;
    void findSubtreeNodes(TreeNode* root,int k){
        if(root==NULL) return;
        if(k==0){
            ans.push_back(root->val);
            return;
        }
        findSubtreeNodes(root->left,k-1);
        findSubtreeNodes(root->right,k-1);
    }
    int nodesAtK(TreeNode* root,TreeNode* target,int k){
        if(root==NULL) return -1;
        if(root==target) {
            findSubtreeNodes(root,k);
            return 0;
        }
        int l = nodesAtK(root->left,target,k);
        if(l!=-1){
            if(k-l-1!=0){
                findSubtreeNodes(root->right,k-l-2);
            }
            else{
                ans.push_back(root->val);
            }
            return l+1;
        }
        int r = nodesAtK(root->right,target,k);
        if(r!=-1){
            if(k-r-1!=0){
                findSubtreeNodes(root->left,k-r-2);
            }
            else{
                ans.push_back(root->val);
            }
            return r+1;
        }
        return -1;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        nodesAtK(root,target,k);
        return ans;
    }
};