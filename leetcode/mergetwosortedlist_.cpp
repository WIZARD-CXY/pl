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
        // This solution use O(min(len(l1),len(l2))) time
        ListNode *dummy=new ListNode(-1);
        ListNode *temp=dummy;
        
        while(l1 && l2){
            if(l1->val<=l2->val){
                temp->next=l1;
                l1=l1->next;
            }else{
                temp->next=l2;
                l2=l2->next;
            }
            temp=temp->next;
        }
        
        temp->next=(l1==NULL?l2:l1);
        return dummy->next;
    }
};