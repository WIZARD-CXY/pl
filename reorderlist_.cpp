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
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return;
        }
        ListNode *slow=head, *fast=head,*pre=NULL;
        
        while(fast && fast->next){
            pre=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        
        //cut two list
        pre->next=NULL;
        //reverse the last part part of list
        
        slow=reverse(slow);
        
        //merge the two list node by node
        
        ListNode *p=head;
        ListNode *q=slow;
        
        // p's len is less or equal to q
        while(p->next){
            ListNode *temp1=p->next;
            ListNode *temp2=q->next;
            p->next=q;
            q->next=temp1;
            p=temp1;
            q=temp2;
        }
        p->next=q;
        
    }
    
    ListNode* reverse(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode* pre=NULL,*cur=head;
        
        while(cur){
            ListNode *next = cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        return pre;
    }
};