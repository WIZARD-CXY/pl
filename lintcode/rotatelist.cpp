/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
        // write your code here
        
        ListNode *pre=NULL,*cur=head;
        int count=0;// list node number
        
        //first reverse the whole list
        while(cur){
            count++;
            ListNode *next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        
        k=k%count;
        
        // reverse first k element
        
        for(int i=0; )
       
    }
};
