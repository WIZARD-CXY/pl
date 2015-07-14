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
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // write your code here
        if(!l1){
            return l2;
        }
        
        if(!l2){
            return l1;
        }
        
        ListNode *mergedhead;
        
        if(l1->val<l2->val){
            mergedhead=l1;
            mergedhead->next=mergeTwoLists(l1->next,l2);
        }else{
            mergedhead=l2;
            mergedhead->next=mergeTwoLists(l1,l2->next);
        }
        
        return mergedhead;
    }
};
