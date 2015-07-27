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
    /**
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2 
     */
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        // write your code here
        int carry=0;
        
        ListNode *dummy = new ListNode(-1);
        ListNode *pre=dummy;
        
        while(l1 || l2 || carry){
            int sum= (l1!=NULL?l1->val:0) + (l2!=NULL?l2->val:0) + carry;
            ListNode *cur = new ListNode(sum%10);
            carry=sum/10;
            pre->next=cur;
            pre=cur;
            
            if(l1){
                 l1=l1->next;
            }
            if(l2){
               l2=l2->next;
            }
            
        }
        
        return dummy->next;
    }
};
