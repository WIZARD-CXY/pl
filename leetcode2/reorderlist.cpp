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
    void reorderList(ListNode* head) {
        //first cut the list into two part
        if(head==NULL || head->next==NULL){
            return;
        }
        ListNode *slow=head,*fast=head;
        ListNode *pre=NULL;
        
        while(fast && fast->next){
            pre=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        
        // the first list's node number
        // is one less or equal to the second one's node number
        pre->next=NULL;
        
        ListNode *cur=slow;
        pre=NULL;
        while(cur){
            ListNode *cnext=cur->next;
            cur->next=pre;
            pre=cur;
            cur=cnext;
        }
        
        ListNode *rhead=pre;
        ListNode *rcur=rhead;
        cur=head;
        
        //splice two list together
        while(cur->next){
            //tmp save the next node
            ListNode *curnext=cur->next;
            ListNode *rcurnext=rcur->next;
            cur->next=rcur;
            rcur->next=curnext;
            cur=curnext;
            rcur=rcurnext;
        }
        cur->next=rcur;
    }
};