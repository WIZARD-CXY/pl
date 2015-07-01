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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy->next=head;
        ListNode* pre = dummy;
        
        for(int i=0; i<m-1; i++){
            pre=pre->next;
        }
        
        ListNode *head2=pre;
        pre=pre->next;
        ListNode* cur=pre->next;
        
        for(int i=m; i<n; i++){
            ListNode *temp = cur->next;
            pre->next=temp;
            cur->next=head2->next;//insert to the head2->next
            head2->next=cur;
            cur=temp;
        }
        return dummy->next;
    }
};