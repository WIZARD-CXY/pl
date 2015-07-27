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
    // use merge sort paradigm
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        //split the list two
        ListNode *fast=head,*slow=head,*pre=NULL;
        
        while(fast && fast->next){
            fast=fast->next->next;
            pre=slow;
            slow=slow->next;
        }
        //cut the list
        pre->next=NULL;
        
        ListNode* lh = sortList(head);
        ListNode* rh = sortList(slow);
        
        return mergeTwoLists(lh,rh);
    }
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2){
        ListNode *dummy = new ListNode(-1);
        ListNode *cur=dummy;
        
        while(l1&&l2){
            if(l1->val<l2->val){
                cur->next=l1;
                l1=l1->next;
            }else{
                cur->next=l2;
                l2=l2->next;
            }
            cur=cur->next;
        }
        
        cur->next=(l1==NULL?l2:l1);
        return dummy->next;
    }
};