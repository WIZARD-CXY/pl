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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next == NULL || k==1){
            return head;
        }
        ListNode *dummy= new ListNode(-1);
        dummy->next=head;
        
        ListNode *preGroup=dummy; // indicate the node which is pre of current group
        ListNode *nextGroup=dummy;// indicate the node which is next to current group
        // preGroup->first.....->last->nextGroup
        int count=0;//current group count
        ListNode *first=head,*last=head;
        while(last){
            count++;
            if(count==k){
                //make a group
                nextGroup=last->next;
                reverseList(first,last);
                // make the list back to the whole list
                preGroup->next=last;
                preGroup=first;
                first->next=nextGroup;
                first=last=nextGroup;
                count=0;// restart a new group
                continue;
            }
            
            last=last->next;
        }
        return dummy->next;
    }
    
    void reverseList(ListNode *head, ListNode *tail){
        ListNode *pre=NULL;
        ListNode *cur=head;
        
        while(pre!=tail){
            ListNode *next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
    }
};