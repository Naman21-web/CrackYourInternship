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
    int cover(TreeNode* root,int &cam){
        if(root==NULL) return 1;
        int left = cover(root->left,cam);
        int right = cover(root->right,cam);
        if(left==0 || right==0){//iske children parent k bharose h parent k paas camera hona chahiye matlab is node k paas camera hona chahiye to cam k value increase karo
            cam++;
            return 2;//because ye node k paas camera h ye iske parent ko bhi monitor kar skta
        }
        if(left==2 || right==2) return 1;//Iske children k paas camera h wo is node k bharose nhi h to ye node already monitored h 1 return kar do

        return 0;//is node k parent k paas camera hona chahiye 
        //is node k paas nhi h ya to ye children k bharose h ya parent k agar children k bharose hota to to upar wale if se 1 return ho jata matlab ye parent k bharose h
    }
    int minCameraCover(TreeNode* root) {
        int cam=0;
        int minicam = cover(root,cam);
        if(minicam==0) cam++;//kyuki iske child root node k bharose h
        return cam;
    }
};