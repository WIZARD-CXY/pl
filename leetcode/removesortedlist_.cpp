/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // this solution do not corrupt the original list
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(head==NULL){
            return NULL;
        }
        
        ListNode *ret = new ListNode(head->val);
        ListNode *tmp = ret;
        ListNode *p = head;
        
        while(p){
            if(tmp->val != p->val){
                ListNode *pp = new ListNode(p->val);
                tmp->next = pp;
                tmp = tmp->next;
            }
            p = p->next;
        }
        return ret;
    }
};