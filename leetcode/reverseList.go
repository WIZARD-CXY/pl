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
    ListNode* reverseListR(ListNode* head) {
        if(head==NULL || head->next ==NULL){
            return head;
        }
        
        ListNode *newhead=reverseList(head->next);
        
        head->next->next=head;
        head->next=NULL;
        
        return newhead;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode *pre=NULL;
        ListNode *cur=head;
        
        while(cur){
            ListNode *next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        
        return pre;
    }
};