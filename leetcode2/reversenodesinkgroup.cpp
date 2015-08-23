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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy=new ListNode(-1);
        ListNode *pre=dummy;
        pre->next=head;
        
        if(k==1){
            return head;
        }
        
        ListNode* cur=dummy;
        
        while(cur){
            int i;
            for(i=0; i<k; i++){
                cur=cur->next;
                if(cur==NULL){
                    break;
                }
            }
            
            if(i==k){
               //now cur is group last
               ListNode *nextgroupfirst=cur->next;
               ListNode *curgrouplast=pre->next;
               
               //cut the list out and reverse
               cur->next=NULL;
               ListNode *newhead=reverseList(pre->next);
               
               //splice in 
               curgrouplast->next=nextgroupfirst;
               pre->next=newhead;
               // move forward
               pre=cur=curgrouplast;
            }else{
                //the last part is not enough
               break; 
            }
        }
        
        return dummy->next;
        
    }
};