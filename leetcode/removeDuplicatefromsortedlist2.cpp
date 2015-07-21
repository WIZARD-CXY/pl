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
        ListNode *dummy= new ListNode(-1);
        dummy->next=head;
        ListNode *pre =dummy;
        ListNode *cur=head;
        
        while(cur){
            bool dup=false;
            while(cur->next !=NULL && cur->val == cur->next->val){
                dup=true;
                ListNode *temp=cur;
                cur=cur->next;
                delete temp;
            }
            
            if(dup){
                //delete the last dup one
                ListNode *temp=cur;
                cur=cur->next;
                delete temp;
                continue;
            }
            
            pre->next=cur;
            pre=cur;
            cur=cur->next;
        }
        pre->next=NULL;
        return dummy->next;
        
    }
};