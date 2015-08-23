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
    struct cmp{
        bool operator()(const ListNode* a, const ListNode *b){
            return a->val>b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*> , cmp> pq;
        
        ListNode *dummy=new ListNode(-1);
        ListNode *pre=dummy;
        for(auto head : lists){
            if(head){
                pq.push(head);
            }
        }
        
        while(!pq.empty()){
            ListNode *tmp=pq.top();
            pq.pop();
            pre->next=tmp;
            if(tmp->next){
                pq.push(tmp->next);
            }
            pre=pre->next;
        }
        
        return dummy->next;
        
    }
};