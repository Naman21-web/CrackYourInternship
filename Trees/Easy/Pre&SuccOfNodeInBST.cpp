/* BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution
{
    public:
    void find(Node* root,Node*& pre,Node*& suc,int key){
        if(root==NULL) return;
        if(root->key==key){
            if(root->left) {
                pre = root->left;
                while(pre->right) pre=pre->right;
            }
            if(root->right){
                suc=root->right;
                while(suc->left) suc=suc->left;
            }
            return;
        }
        else if(root->key>key){
            suc=root;
            find(root->left,pre,suc,key);
        }
        else{
            pre=root;
            find(root->right,pre,suc,key);
        }
    }
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
        pre=NULL,suc=NULL;
        find(root,pre,suc,key);
    }
};