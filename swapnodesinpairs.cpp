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
    ListNode* swapPairs(ListNode* head) {
        ListNode *p1=head;
        ListNode *p2=head;
        ListNode *pre=NULL;
        
        while(p1 && p1->next){
            ListNode *p2 = p1->next;
            p1->next=p2->next;
            p2->next=p1;
            
            if(pre==NULL){
                head=p2;
            }else{
                pre->next=p2;
            }
            pre=p1;
            p1=p1->next;
            
        }
        
        return head;
        
    }
};