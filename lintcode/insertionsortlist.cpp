/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: The head of linked list.
     */
    ListNode *insertionSortList(ListNode *head) {
        // write your code here
        ListNode *dummy= new ListNode(-1);
        ListNode *cur=head;
        
        while(cur){
            //find the first node that value is larger than cur->val
            ListNode* pre=dummy;
            while(pre->next && pre->next->val<=cur->val){
                pre=pre->next;
            }
            
            // save the cur->next first
            ListNode *next=cur->next;
            
            //pre is pre insertion point
            cur->next=pre->next;
            pre->next=cur;
            
            cur=next;
        }
        return dummy->next;
    }
};
