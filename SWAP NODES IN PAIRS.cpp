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
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp=head;
        int c=0;
        ListNode* prevNode = NULL;
        while(temp!=NULL){
            
            ListNode* nextNode=temp->next;
            if(temp->next!=NULL){
                temp->next=nextNode->next;
                nextNode->next=temp;
                if(c==0){
                    head=nextNode;
                }
                if(c!=0){
                    prevNode->next=nextNode;

                }

            }
            c++;
           prevNode=temp;
            temp=temp->next;
        }
        return head;
        
    }
};
