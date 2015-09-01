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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        ListNode *dummy=new ListNode(-1);
        ListNode *pre=dummy;
        pre->next=head;
        
        ListNode *cur=head;
        
        while(cur){
            bool dup=false;
            while(cur->next && cur->val==cur->next->val){
                dup=true;
                ListNode *tmp=cur;
                cur=cur->next;
                delete tmp;
            }
            
            if(dup){
                //delete the last dup one 
                ListNode *tmp=cur;
                cur=cur->next;
                delete tmp;
                
            }else{
                // no dup just move pre and cur
                pre->next=cur;
                pre=cur;
                cur=cur->next;
            }
            
            
        }
        pre->next=NULL;
        
        return dummy->next;
    }
};