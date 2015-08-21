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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy=new ListNode(-1);
        ListNode *pre=dummy;
        
        while(l1 && l2){
            if(l1->val<l2->val){
                pre->next=l1;
                l1=l1->next;
                
            }else{
                pre->next=l2;
                l2=l2->next;
            }
            
            pre=pre->next;
        }
        
        pre->next=l1?l1:l2;
        
        return dummy->next;
    }
};