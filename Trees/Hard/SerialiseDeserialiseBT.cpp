/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    vector<int> serialize(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node!=NULL) ans.push_back(node->val);
            else ans.push_back(1e9);
            if(node!=NULL){
                q.push(node->left);
                q.push(node->right);
            }
        }
        // cout<<ans.size();
        for(auto node:ans) cout<<node<<" ";
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(vector<int> data) {
        if(data[0]==1e9) return NULL;
        int idx=0;
        TreeNode* root = new TreeNode(data[idx++]);
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty() && idx<data.size()){
            TreeNode* node = q.front();
            q.pop();
            if(data[idx]!=1e9){
                TreeNode* leftnode = new TreeNode(data[idx]);
                node->left = leftnode;
                q.push(leftnode);
            }
            else node->left=NULL;
            idx++;
            if(data[idx]!=1e9){
                TreeNode* rightnode = new TreeNode(data[idx]);
                node->right = rightnode;
                q.push(rightnode);
            }
            else node->right=NULL;
            idx++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));