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
     * @param x: an integer
     * @return: a ListNode 
     */
    ListNode *partition(ListNode *head, int x) {
        // write your code here
        ListNode *leftdummy= new ListNode(-1);
        ListNode *leftcur=leftdummy;
        ListNode *rightdummy=new ListNode(-1);
        ListNode *rightcur=rightdummy;
        ListNode *cur=head;
        while(cur){
            if(cur->val<x){
                leftcur->next=cur;
                leftcur=leftcur->next;
            }else{
                rightcur->next=cur;
                rightcur=rightcur->next;
            }
            cur=cur->next;
        }
        
        //splice two list
        leftcur->next=rightdummy->next;
        rightcur->next=NULL;
    
        return leftdummy->next;
    }
};



