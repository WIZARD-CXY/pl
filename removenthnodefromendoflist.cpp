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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(head==NULL){
            return NULL;
        }
        
        ListNode *p=head;
        ListNode *q=head;
        ListNode *prep=NULL;
        
        for(int i=0; i<n-1 ; i++){
            q=q->next;
        }
        
        while(q->next){
            prep=p;
            p=p->next;
            q=q->next;
        }
        if(prep == NULL){
            head=p->next;
            delete p;
            
        }else {
            prep->next=p->next;
            delete p;
        }
        return head;
        
    }
};