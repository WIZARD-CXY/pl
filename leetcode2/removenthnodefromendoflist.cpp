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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy =new ListNode(-1);
        
        ListNode *slow=dummy;
        ListNode *fast=dummy;
        dummy->next=head;
        
        for(int i=0; i<n; i++){
            fast=fast->next;
        }
        
        while(fast->next){
            fast=fast->next;
            slow=slow->next;
        }
        
        ListNode *tmp=slow->next;
        slow->next=tmp->next;
        delete tmp;
        
        return dummy->next;
    }
};