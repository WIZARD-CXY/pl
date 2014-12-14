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
    ListNode *deleteDuplicates(ListNode *head) {
        if(head==NULL){
            return NULL;
        }
        int val=INT_MAX;
        ListNode *p=head;
        ListNode *prep=NULL;
        
        while(p){
            if(p->val!=val){
                val=p->val;
                prep=p;
                p=p->next;
            }else{
                prep->next=p->next;
                delete p;
                p=prep->next;
            }
        }
        return head;
        
        
    }
};