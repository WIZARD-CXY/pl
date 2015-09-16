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
    ListNode *reverselist(ListNode *head){
        ListNode *pre=NULL;
        ListNode *cur=head;
        
        while(cur){
            ListNode *cnext=cur->next;
            cur->next=pre;
            pre=cur;
            cur=cnext;
        }
        
        return pre;
    }
    bool isPalindrome(ListNode* head) {
      ListNode *slow=head,*fast=head;
      ListNode *pre;
      while(fast && fast->next){
          pre=slow;
          slow=slow->next;
          fast=fast->next->next;
      }
      
      //split into two list
      pre->next=NULL;
      ListNode *newhead;
      if(fast==NULL){
           //even number list node
          newhead=reverselist(slow);
      }else{
           //odd number list node
          newhead=reverselist(slow->next);
      }
      
      while(head && newhead){
          if(head->val != newhead->val){
              return false;
          }
          head=head->next;
          newhead=newhead->next;
      }
      
      return true;
    }
};