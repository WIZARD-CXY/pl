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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(0);
        ListNode *pre = head;
        int sum=0;
        int carry=0;
        
        while(l1 != NULL || l2 != NULL || carry!=0){
            ListNode *temp = new ListNode(0);
            if(l1!=NULL && l2 !=NULL){
                sum=l1->val+l2->val+carry;
                l1=l1->next;
                l2=l2->next;
            }else if( l1!=NULL ){
                sum=l1->val+carry;
                l1=l1->next;
            }else if ( l2!=NULL){
                sum=l2->val+carry;
                l2=l2->next;
            }else{
                sum=carry;
            }
            carry=sum/10;
            sum=sum%10;
            
            temp->val=sum;
            pre->next=temp;
            pre=temp;
        }
        
        return head->next;
        
    }
};