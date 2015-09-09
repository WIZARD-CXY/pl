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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy=new ListNode(-1);
        ListNode *cur=head;
        
        while(cur){
            ListNode *pre=dummy;
            //find the insertion point
            while(pre->next && pre->next->val<=cur->val){
                pre=pre->next;
            }
            ListNode *cnext=cur->next;
            cur->next=pre->next;
            pre->next=cur;
            cur=cnext;
        }
        return dummy->next;
    }
};