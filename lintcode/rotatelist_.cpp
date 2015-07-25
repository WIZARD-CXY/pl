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
        if(head==NULL){
            return head;
        }
        ListNode *pre=NULL,*cur=head;
        int n=0;// list node number
        
        //first reverse the whole list
        while(cur){
            n++;
            ListNode *next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        
        k=k%n;
        
        if(k==0){
            return head;
        }
        
        // reverse first k element
        ListNode *reversehead=pre;
        pre=NULL;
        cur=reversehead;
        
        for(int i=0; i<k; i++){
            ListNode *next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        ListNode *newhead=pre;
        pre=NULL;
        
        // reverse last element
        for(int i=0; i<(n-k); i++){
            ListNode *next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        
        reversehead->next=pre;
        
        return newhead;
       
    }
};
