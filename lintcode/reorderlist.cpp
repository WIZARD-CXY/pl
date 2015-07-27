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
     * @return: void
     */
    void reorderList(ListNode *head) {
        // write your code here
        if(head==NULL || head->next==NULL){
            return;
        }
        
        //split list into two
        ListNode *slow=head,*fast=head;
        ListNode *pre=NULL;
        while(fast && fast->next){
            pre=slow;
            slow=slow->next;
            fast=fast->next->next;
        }

        pre->next=NULL;
        
        // reverse the right list
        pre=NULL;
        while(slow){
            ListNode *next=slow->next;
            slow->next=pre;
            pre=slow;
            slow=next;
        }
        
        ListNode *reversehead=pre;
        
        //splice two list into one
        ListNode *cur=head,*rcur=reversehead;
        //cur list noe number is one less or equal to rcur list node number
        while(cur->next){
            //save the next pointer first
            ListNode *next=cur->next;
            ListNode *rnext=rcur->next;
            
            //splice two nodes 
            cur->next=rcur;
            rcur->next=next;
            //move forward
            cur=next;
            rcur=rnext;
        }
        
        cur->next=rcur;
        
    }
};



