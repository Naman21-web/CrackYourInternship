

/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/
    // Node* mergeSorted(Node* l1,Node* l2){
    //     Node* dummyNode=new Node(-1);
    //     Node* temp=dummyNode;
    //     while(l1 && l2){
    //         if(l1->data<l2->data){
    //             temp->bottom=l1;
    //             l1=l1->bottom;
    //         }
    //         else{
    //             temp->bottom=l2;
    //             l2=l2->bottom;
    //         }
    //         temp=temp->bottom;
    //     }
    //     if(l1!=NULL){
    //         temp->bottom=l1;
    //     }
    //     if(l2){
    //         temp->bottom=l2;
    //     }
    //     return dummyNode->bottom;
    // }
    
    // Node* merge(Node* l1,Node* l2){
    //     Node* dummyNode=new Node(-1);
    //     Node* temp=dummyNode;
    //     while(l1 && l2){
    //         if(l1->data<l2->data){
    //             temp->next=l1;
    //             l1=l1->next;
    //         }
    //         else{
    //             temp->next=l2;
    //             l2=l2->next;
    //         }
    //         temp=temp->next;
    //     }
    //     if(l1!=NULL){
    //         temp->next=l1;
    //     }
    //     if(l2){
    //         temp->next=l2;
    //     }
    //     return dummyNode->next;
    // }

    // Node* sort(Node* head){
    //     if(head->next==NULL) return head;
    //     Node* slow=head;
    //     Node* fast=head;
    //     Node* prev=slow;
    //     while(fast && fast->next){
    //         prev=slow;
    //         slow=slow->next;
    //         fast=fast->next->next;
    //     }
    //     prev->next=NULL;
    //     fast=head;
    //     return merge(sort(slow),sort(fast));
    // }
/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root)
{
   // Your code here
  vector<int> ans;
  while(root!=NULL){
    //   ans.push_back(root->data);
      Node* temp=root;
      while(temp->bottom!=NULL){
          ans.push_back(temp->data);
          temp=temp->bottom;
      }
      ans.push_back(temp->data);
      root = root->next;
  }
//   for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    sort(ans.begin(),ans.end());
    int i=0;
    Node* dummyNode = new Node(-1);
    Node* temp=dummyNode;
    while(i<ans.size()){
        temp->bottom = new Node(ans[i++]);
        temp=temp->bottom;
    }
  return dummyNode->bottom;

    // if(root->next==NULL) return root;
    // root=sort(root);
    // Node* ans = mergeSorted(root,root->next);
    // root=root->next->next;
    // while(root){
    //     ans = mergeSorted(ans,root);
    //     root=root->next;
    // }
    // return ans;
}