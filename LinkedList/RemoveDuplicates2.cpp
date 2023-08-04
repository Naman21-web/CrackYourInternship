/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* temp=head;
        ListNode* newNode=new ListNode(-1);
        ListNode* tempnewNode=newNode;
        int cnt=1;
        while(temp!=NULL){
            if(temp->next && temp->next->val==temp->val){
                cnt++;
            }
            else{
                if(cnt==1){
                    tempnewNode->next=temp;
                    tempnewNode  = tempnewNode->next;
                }
                else{
                    cnt=1;
                }
            }
            temp=temp->next;
            tempnewNode->next=NULL;
        }
        return newNode->next;
    }
};