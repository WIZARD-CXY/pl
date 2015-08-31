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
        if(head == NULL || head->next==NULL){
            return head;
        }
        
        ListNode *pre=head;
        ListNode *cur=head->next;
        
        while(cur){
            if(cur->val==pre->val){
                //do not move pre pointer
                ListNode *tmp=cur;
                cur=cur->next;
                
                delete tmp;
            }else{
                //move pre pointer to cur
                pre=cur;
                cur=cur->next;
            }
            pre->next=cur;
        }
        
        return head;
    }
};