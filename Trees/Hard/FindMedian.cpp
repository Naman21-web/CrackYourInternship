int countNodes(Node* root){
    int count=0;
    Node* curr = root;
    while(curr){
        if(!curr->left){
            count++;
            curr = curr->right;
        }
        else{
            Node* pre = curr->left;
            while(pre->right && pre->right!=curr){
                pre = pre->right;
            }
            if(!pre->right){
                pre->right=curr;
                curr=curr->left;
            }
            else{
                count++;
                pre->right=NULL;
                curr = curr->right;
            }
        }
    }
    return count;
}
float findMedian(struct Node *root)
{
      //Code here
      int n = countNodes(root);
      int med = (n+2)/2;
      int count=0;
      Node* prev;
      Node* curr=root;
      while(curr){
        if(!curr->left){
            count++;
            if(count==med){
                if(n%2==0){
                    return (float)(prev->data+curr->data)/2.0;
                }
                else return (float)curr->data;
            }
            prev=curr;
            curr = curr->right;
        }
        else{
            Node* pre = curr->left;
            while(pre->right && pre->right!=curr){
                pre = pre->right;
            }
            if(!pre->right){
                pre->right=curr;
                curr=curr->left;
            }
            else{
                count++;
                if(count==med){
                    if(n%2==0){
                        return (float)(prev->data+curr->data)/2.0;
                    }
                    else return (float)curr->data;
                }
                prev=curr;
                pre->right=NULL;
                curr = curr->right;
            }
        }
    }
}