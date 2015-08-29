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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL){
            return NULL;
        }
        int n=0;
        
        ListNode *p=head;
        
        while(p){
            n++;
            p=p->next;
        }
        
        k=k%n;
        
        if(k==0){
            return head;
        }
        
        int step=n-k;
        
        p=head;
        
        while(--step){
            p=p->next;
        }
        //cut the list
        ListNode *newhead=p->next;
        p->next=NULL;
        
        p=newhead;
        while(p->next){
            p=p->next;
        }
        p->next=head;
        
        return newhead;
    }
};