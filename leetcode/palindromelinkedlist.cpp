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
    ListNode* reverseList(ListNode *head){
        ListNode *pre=NULL,*cur=head;
        
        while(cur){
            ListNode *next =cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        return pre;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head, *fast=head;
        ListNode *pre;
        // split the list into two
        while(fast && fast->next){
            pre=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        
        //cut the list
        pre->next=NULL;
        ListNode* head2;
        if(fast==NULL){
             // even ListNode number
             head2=slow;
        }else{
            //odd ListNode number
             head2=slow->next;
        }
        
        ListNode *head3=reverseList(head2);
       
        while(head  && head3){
            if(head->val != head3->val){
                return false;
            }
            head=head->next;
            head3=head3->next;
        }
        
        return true;
    }
};