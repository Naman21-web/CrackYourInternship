Node* reverse(Node* head,int &len){
    // while()
    Node* currptr=head;
    Node* prevptr = NULL;
    Node* nextptr;
    while(currptr){
        len++;
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr=currptr;
        currptr = nextptr;
    }
    return prevptr;
}

Node* subLinkedList(Node* l1, Node* l2)
{
    //Your code here
    int len1=0,len2=0;
    while(l1 && l1->data==0) l1=l1->next;//Removing leading zeroes
    if(!l1) return l2;//If all are zeroes
    while(l2 && l2->data==0) l2=l2->next;
    if(!l2) return l1;
    
    bool check=false;//To see which is greater if len of both are same
    Node* temp1=l1;
    Node* temp2=l2;
    while(temp1 && temp2 && temp1->data==temp2->data){
        temp1=temp1->next;
        temp2 = temp2->next;
    }//till starting val of both no is same
    if(!temp1 && !temp2) return new Node(0);//If reached till last it ,means both no are same so return 0
   
    if(temp1 && temp2 && temp1->data<temp2->data) check = true;//making check true if l2>l1 as we need to swap
    
    //Reversing both list to subtract
    l1=reverse(l1,len1);
    l2=reverse(l2,len2);
    
    //if l2 is bigger than l2 so swap l1 and l2
    if(len2>len1 || (len1==len2 && check)){
        Node* temp=l1;
        l1=l2;
        l2=temp;
    }
    
    //To store result list
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;
    int carry=0;
    while(l1 && l2){
        int resvalue = l1->data-l2->data+carry;
        if(resvalue<0){
            resvalue += 10;
            carry = -1;
        }
        else carry=0;
        l1 = l1->next;
        l2 = l2->next;
        temp->next = new Node(resvalue);
        temp = temp->next;
    }
    
    //As l2 is smaller than l1 so l1 will never finish before l2
    while(l1){//If l2 finishes 
        int resvalue = l1->data+carry;
        if(resvalue<0){
            resvalue += 10;
            carry=-1;
        }
        else carry=0;
        temp->next = new Node(resvalue);
        temp = temp->next;
        l1 = l1->next;
    }
    
    //Reversing result list
    dummyNode->next=reverse(dummyNode->next,len1);
    while(dummyNode->next->data==0) dummyNode=dummyNode->next;//removing leading zeroes
    return dummyNode->next;
}