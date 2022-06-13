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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum=0;
        int carry=0;
        ListNode* prevN=NULL;
        ListNode* head;
        while(l1 && l2){
            sum=l1->val+l2->val+carry;
            carry=sum/10;
            ListNode* newN=new ListNode(sum%10);
            if(prevN){
                prevN->next=newN;
            }
            else{
                head=newN;
            }
            prevN=newN;
            l1=l1->next;
            l2=l2->next;
            
        }
        while(l1){
            sum=l1->val+carry;
            carry=sum/10;
            ListNode* newN=new ListNode(sum%10);
            if(prevN){
                prevN->next=newN;
            }
            prevN=newN;
            l1=l1->next;
        }
        while(l2){
            sum=l2->val+carry;
            carry=sum/10;
            ListNode* newN=new ListNode(sum%10);
            if(prevN){
                prevN->next=newN;
            }
            prevN=newN;
            l2=l2->next;
        }
        if(carry==1){
            ListNode* newN=new ListNode(1);
            if(prevN){
                prevN->next=newN;
            }
            newN->next=NULL;
        }
        return head;
        
    }
};
