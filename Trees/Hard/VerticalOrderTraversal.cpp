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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        map<int,vector<int>> mp;
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int dis = q.front().second;
            mp[dis].push_back(node->val);
            q.pop();
            if(node->left) q.push({node->left,dis-1});
            if(node->right) q.push({node->right,dis+1});
        }
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};