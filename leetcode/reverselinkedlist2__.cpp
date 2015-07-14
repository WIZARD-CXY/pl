/**
 * Definition of singly-linked-list:
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @param m: The start position need to reverse.
     * @param n: The end position need to reverse.
     * @return: The new head of partial reversed linked list.
     */
    ListNode* reverseList(ListNode *head){
        ListNode *cur=head,*pre=NULL;
        
        while(cur){
            ListNode *next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        
        return pre;
    }
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // write your code here
        if(head==NULL){
            return head;
        }
        if(m==n){
            return head;
        }
        
        ListNode *dummy = new ListNode(-1);
        dummy->next=head;
        ListNode *p=head,*prep=dummy;
        
        while(--m){
            prep=p;
            p=p->next;
        }
        
        ListNode *q=head;
        
        while(--n){
            q=q->next;
        }
        
        ListNode *qnext=q->next;
        q->next=NULL;
        //reverse list
        ListNode *rhead=reverseList(p);
        prep->next=rhead;
        p->next=qnext;
        
        return dummy->next;
    }
};