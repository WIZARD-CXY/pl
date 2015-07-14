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
     * @param n: An integer.
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // write your code here
        ListNode *dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* p=dummy,*q=dummy;
        
        while(n--){
            p=p->next;//p goes first n steps prior to the head
        }
        
        while(p->next){
            p=p->next;
            q=q->next;
        }
        // q points to the nodes which is prev of node to be deleted
        ListNode *temp=q->next;
        q->next=q->next->next;
        
        delete temp;
        return dummy->next;
    }
};
