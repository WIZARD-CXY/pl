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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode *dummy=new ListNode(-1);
        ListNode *pre=dummy;
        
        while(l1 || l2 || carry!=0){
            int sum=0;
            if(l1!=NULL && l2!=NULL){
                sum=l1->val+l2->val+carry;
                l1=l1->next;
                l2=l2->next;
            }else if(l2!=NULL){
                sum=l2->val+carry;
                l2=l2->next;
            }else if(l1!=NULL){
                sum=l1->val+carry;
                l1=l1->next;
            }else{
                sum=carry;
            }
            ListNode *node=new ListNode(sum%10);
            carry=sum/10;
            
            pre->next=node;
            pre=node;
        }
        return dummy->next;
    }
};s