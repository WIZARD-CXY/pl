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
    ListNode* partition(ListNode* head, int x) {
        ListNode *left_dummy= new ListNode(-1);
        ListNode *right_dummy = new ListNode(-1);
        
        ListNode *leftcur = left_dummy;
        ListNode *rightcur = right_dummy;
        ListNode *cur=head;
        
        while(cur!=NULL){
            if(cur->val<x){
                leftcur->next=cur;
                leftcur=cur;
            }else{
                rightcur->next=cur;
                rightcur=cur;
            }
            cur=cur->next;
        }
        
        leftcur->next=right_dummy->next;
        rightcur->next=NULL;
        
        return left_dummy->next;
        
    }
};