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
    vector<TreeNode*> constructTree(int start,int end){
        vector<TreeNode*> trees;
        if(start>end){
            trees.push_back(NULL);
            return trees;
        }
        for(int i=start;i<=end;i++){
            vector<TreeNode*> leftTree = constructTree(start,i-1);
            vector<TreeNode*> rightTree = constructTree(i+1,end);
            for(int j=0;j<leftTree.size();j++){
                TreeNode* left = leftTree[j];
                for(int k=0;k<rightTree.size();k++){
                    TreeNode* right = rightTree[k];
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    trees.push_back(root);
                }
            }
        }
        return trees;
    }
    vector<TreeNode*> generateTrees(int n) {
        return constructTree(1,n);
    }
};