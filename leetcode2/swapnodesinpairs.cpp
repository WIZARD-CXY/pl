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
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy= new ListNode(-1);
        ListNode *pre=dummy;
        
        ListNode *cur=head;
        pre->next=head;
        //pre denotes the previous group's last node
        //nextgroupfirst denotes the next group's first node
        while(cur && cur->next){
            ListNode *nextgroupfirst=cur->next->next;
            
            pre->next=cur->next;
            cur->next->next=cur;
            cur->next=nextgroupfirst;
            
            pre=cur;
            cur=nextgroupfirst;
        }
        
        return dummy->next;      
    }
};