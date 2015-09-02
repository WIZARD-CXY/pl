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
    ListNode *reverseList(ListNode *head){
        ListNode *pre=NULL;
        ListNode *cur=head;
        
        while(cur){
            ListNode *next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        return pre;
    }
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *dummy=new ListNode(-1);
        ListNode *pre=dummy;
        pre->next=head;
        
        if(m==n){
            return head;
        }
        
        ListNode *cur=dummy;
        
        while(--m){
            cur=cur->next;
        }
        //cur is lasttail
        ListNode *lasttail=cur;
        ListNode *firsthead=cur->next;
        
        //move forward the cur to n
        cur=dummy;
        while(n--){
            cur=cur->next;
        }
        ListNode *nextfirst=cur->next;
        cur->next=NULL;
        ListNode *newhead=reverseList(firsthead);
        
        //splice the list
        lasttail->next=newhead;
        firsthead->next=nextfirst;
        
        return dummy->next;
    }
};