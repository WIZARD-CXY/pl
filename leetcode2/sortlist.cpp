/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        //use merge sort to sort list
        if(head==NULL || head->next==NULL){
            return head;
        }
        //cut the list into 2
        ListNode *slow=head,*fast=head;
        ListNode *pre=NULL;
        while(fast && fast->next){
            pre=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        pre->next=NULL;
        ListNode *l1=sortList(head);
        ListNode *l2=sortList(slow);
        
        ListNode *newhead=merge(l1,l2);
        
        return newhead;
    }
    ListNode* merge(ListNode *l1, ListNode *l2){
        ListNode* dummy=new ListNode(-1);
        ListNode* pre=dummy;
        
        while(l1 && l2){
            if(l1->val<l2->val){
                pre->next=l1;
                l1=l1->next;
            }else{
                pre->next=l2;
                l2=l2->next;
            }
            pre=pre->next;
        }
        
        pre->next=(l1!=NULL)?l1:l2;
        return dummy->next;
        
    }
};