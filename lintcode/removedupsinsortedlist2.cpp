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
class Solution{
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode * deleteDuplicates(ListNode *head) {
        // write your code here
        ListNode *dummy = new ListNode(-1);
        dummy->next=head;
        ListNode *cur=head;
        ListNode *pre=dummy;
        
        while(cur){
            bool dup=false;
            
            //remove consecutive dups
            while(cur->next && cur->val == cur->next->val){
                dup=true;
                ListNode *temp=cur;
                cur=cur->next;
                delete temp;
            }
            //remove the last one
            if(dup){
                ListNode *temp=cur;
                cur=cur->next;
                delete temp;
                //we can't go further because 
                //we need to check cur and cur->next is same or not so continue to
                //top of the loop
                continue;
            }
            
            pre->next=cur;
            pre=cur;
            cur=cur->next;
        }
        pre->next=NULL;
        return dummy->next;
        
    }
};
