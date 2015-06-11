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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode* pre=NULL,*cur=head;
        
        while(cur){
            ListNode *next = cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        return pre;
        
    }
};