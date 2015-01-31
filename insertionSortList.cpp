class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode *dummy = new ListNode(-1);
        
        while(head){
            
            ListNode *cur = dummy;
            
            while(cur->next && cur->next->val < head->val){
                cur=cur->next;
            }
            //save the head->next first
            ListNode *temp = head->next;
            //insert head into the list following cur
            head->next=cur->next;
            cur->next=head;
            
            // move forward
            head=temp;
        }
        return dummy->next;
    }
};