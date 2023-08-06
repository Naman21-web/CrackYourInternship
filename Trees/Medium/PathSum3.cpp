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
    // int cnt=0;
    int calcPath(TreeNode* root, int targetSum,vector<int> &vec){
        if(root==NULL) return 0;
        int ans=0;
        vec.push_back(root->val);
        ans += calcPath(root->left,targetSum,vec);
        ans += calcPath(root->right,targetSum,vec);
        long long sum=0;
        for(int j=vec.size()-1;j>=0;j--){
            sum += vec[j];
            if(sum==targetSum) ans++;
        }
        vec.pop_back();
        return ans;
    }
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> vec;
        return calcPath(root,targetSum,vec);
        // return cnt;
    }
};