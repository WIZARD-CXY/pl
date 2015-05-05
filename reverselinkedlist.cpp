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
    ListNode* reverseList(ListNode* head) {
        ListNode* p=head;
        if(p==NULL){
            return NULL;
        }
        
        ListNode *q= p->next;
        ListNode *temp;
    
        while(q!=NULL){
            temp=q->next;
            q->next=p;
            p=q;
            q=temp;
        }
        head->next=NULL;
        return p;
        
    }
};