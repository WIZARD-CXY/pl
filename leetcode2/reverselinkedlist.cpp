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
        ListNode *pre=NULL,*cur=head;
        
        while(cur){
            ListNode *cnext=cur->next;
            cur->next=pre;
            pre=cur;
            cur=cnext;
        }
        
        return pre;
    }
};