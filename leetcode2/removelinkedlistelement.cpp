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
        ListNode *dummy=new ListNode(-1);
        ListNode *pre=dummy;
        
        ListNode *cur=head;
        
        while(cur){
            if(cur->val==val){
                ListNode *tmp=cur;
                cur=cur->next;
                delete tmp;
            }else{
                pre->next=cur;
                pre=cur;
                cur=cur->next;
            }
            
        }
        pre->next=NULL;
        
        return dummy->next;
    }
};