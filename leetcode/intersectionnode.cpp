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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int alen=getLen(headA);
        int blen=getLen(headB);
        
        
        ListNode *fast,*slow;
        int diff=abs(alen-blen);
        
        if(alen>blen){
            fast=headA;
            slow=headB;
        }else{
            fast=headB;
            slow=headA;
        }
        
        while(diff--){
            fast=fast->next;
        }
        
        while (slow && fast){
            if(slow==fast){
                return slow;
            }
            slow=slow->next;
            fast=fast->next;
        }
        
        return NULL;
        
    }
    
    int getLen(ListNode *head){
        ListNode *cur=head;
        int len=0;
        
        while(cur){
            len++;
            cur=cur->next;
        }
        
        return len;
    }
};