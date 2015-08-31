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
     * @return: head node
     */
    ListNode *deleteDuplicates(ListNode *head) {
        // write your code here
        if(head==NULL){
            return head;
        }

        ListNode* pre=head,*cur=head->next;
        
        while(cur){
            if(cur->val == pre->val){
                //duplicate just move cur
                ListNode *temp=cur;
                delete temp;
            }else{
                //move pre pointers forward
                pre=cur;
            }
            
            cur=cur->next;
            pre->next=cur;
        }
        
        return head;
    }
};
