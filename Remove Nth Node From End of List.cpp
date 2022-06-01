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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        ListNode* temp2=head;
        int i=0;
        while(temp2!=NULL && i<n){
            temp2=temp2->next;
            i++;
        }
        while(temp2!=NULL && temp2->next!=NULL){
            temp=temp->next;
            temp2=temp2->next;
        }
        if(temp2==NULL && temp==head){
            head=temp->next;
        }
        else{
        ListNode* remove_node=temp->next;
        if(remove_node!=NULL){
        ListNode* next_remove=remove_node->next;
        temp->next=next_remove;
        }
        }
        return head;
        
    }
};

