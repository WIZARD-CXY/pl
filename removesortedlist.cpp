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
        if(head==NULL){
            return NULL;
        }
        int val=head->val;
        ListNode *cur=head->next;
        ListNode *pre=head;
        
        while(cur){
            if(cur->val==val){
                pre->next=cur->next;
                delete cur;
                cur=pre->next;
            }else{
                pre=cur;
                val=cur->val;
                cur=cur->next;
            }   
        }
        return head;   
    }
};