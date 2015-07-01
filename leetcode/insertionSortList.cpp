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
            //save the head->next first
            ListNode *temp = cur->next;
            //insert head into the list following cur
            cur->next=pre->next;
            pre->next=cur;
            
            // move cur forward one step
            cur=temp;
        }
        return dummy->next;
    }
};