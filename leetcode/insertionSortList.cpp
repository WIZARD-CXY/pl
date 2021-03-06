class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode *dummy = new ListNode(-1);
        ListNode *cur=head;
        
        while(cur){
            ListNode *pre = dummy;
            
            while(pre->next && pre->next->val <= cur->val){
                pre=pre->next;
            }
            //save the cur->next first
            ListNode *temp = cur->next;
            //insert cur into the list following pre
            cur->next=pre->next;
            pre->next=cur;
            
            // move cur forward one step
            cur=temp;
        }
        return dummy->next;
    }
};