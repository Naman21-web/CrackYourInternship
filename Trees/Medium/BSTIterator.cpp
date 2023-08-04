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
class BSTIterator {
public:
// Dry run this code you will understand approach
//Basically first traversing all left nodes after that we get root and after traversing root going to right subtree of each root
//This is the inorder traversal sequence 
    stack<TreeNode*> st;
    void pushAll(TreeNode* root){
        while(root->left) {st.push(root->left); root=root->left;}
    }
    BSTIterator(TreeNode* root) {
        st.push(root);
        pushAll(root);
    }
    
    int next() {
        TreeNode* curr=st.top();
        st.pop();
        if(curr->right){
            st.push(curr->right);
            pushAll(curr->right);
        }
        return curr->val;
    }
    
    bool hasNext() {
        if(!st.empty()) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */