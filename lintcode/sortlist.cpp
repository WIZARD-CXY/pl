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
     * @return: You should return the head of the sorted linked list,
                    using constant space complexity.
     */
    ListNode *sortList(ListNode *head) {
        // write your code here
        // use divide and conquer paradigm
        // first split the list into two
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        ListNode *slow=head,*fast=head;
        ListNode *pre=NULL;
        while(fast && fast->next){
            pre=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        
        pre->next=NULL;
        
        // sort two small list
        ListNode *lh=sortList(head);
        ListNode *rh=sortList(slow);
        
        // merge two sorted list
        return mergeTwoList(lh,rh); 
        
    }
    ListNode* mergeTwoList(ListNode *l1, ListNode *l2){
        ListNode *dummy=new ListNode(-1);
        ListNode *cur=dummy;
        
        while(l1 && l2){
            if(l1->val < l2->val){
                cur->next=l1;
                l1=l1->next;
            }else{
                cur->next=l2;
                l2=l2->next;
            }
            cur=cur->next;
        }
        
        cur->next=(l1==NULL)?l2:l1;
        
        return dummy->next;
    }
};