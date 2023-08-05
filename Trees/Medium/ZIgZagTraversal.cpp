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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        stack<TreeNode*> currlevel,nextlevel;
        bool lefttoright=true;
        currlevel.push(root);
        vector<int> level;
        while(!currlevel.empty()){
            TreeNode* temp = currlevel.top();
            level.push_back(temp->val);
            currlevel.pop();
            if(lefttoright){
                if(temp->left)nextlevel.push(temp->left);
                if(temp->right) nextlevel.push(temp->right);
            }
            else{
                if(temp->right) nextlevel.push(temp->right);
                if(temp->left) nextlevel.push(temp->left);
            }
            if(currlevel.empty()){
                ans.push_back(level);
                level.clear();
                lefttoright = !lefttoright;
                currlevel=nextlevel;
                while(!nextlevel.empty()) nextlevel.pop();
            }
        }
        return ans;
    }
};