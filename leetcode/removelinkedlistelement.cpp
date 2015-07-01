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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL){
            return NULL;
        }
        while(head && head->val==val){
            head=head->next;
        }
        
        ListNode* pre=NULL;
        ListNode* p=head;
        
        // we use pre to indicate the valid node and p to indicate next valid candidate 
        // valid means the node->val is not val
        while(p){
            if(p->val==val){
                //don't move pre 
                pre->next=p->next;
                ListNode* temp=p;
                p=p->next;
                delete temp;
            }else{
                pre=p;
                p=p->next;
                
            }
        }
        return head;
    }
};