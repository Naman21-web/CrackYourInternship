class Solution
{
    public:
    Node* reverse(Node* head){
        Node* currptr=head;
        Node* nextptr;
        Node* prevptr =NULL;
        while(currptr){
            nextptr  = currptr->next;
            currptr->next = prevptr;
            prevptr = currptr;
            currptr = nextptr;
        }
        return prevptr;
    }
    Node *compute(Node *head)
    {
        // your code goes here
        head=reverse(head);
        stack<int> st;
        Node* temp = head;
        Node* result = new Node(temp->data);
        st.push(temp->data);
        temp = temp->next;
        while(temp){
            while(!st.empty() && temp->data>=st.top()) st.pop();
            if(st.empty()){
                Node* newnode = new Node(temp->data);
                newnode->next = result;
                result = newnode;
            }
            st.push(temp->data);
            temp=temp->next;
        }
        return result;
    }
    
};