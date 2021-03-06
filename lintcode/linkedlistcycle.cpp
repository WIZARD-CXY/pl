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
     * @return: True if it has a cycle, or false
     */
    bool hasCycle(ListNode *head) {
        // write your code here
        if(head==NULL){
            return false;
        }
        ListNode *slow=head,*fast=head;
        
        while(slow && fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast){
                return true;
            }
        }
        
        return false; 
    }
};



