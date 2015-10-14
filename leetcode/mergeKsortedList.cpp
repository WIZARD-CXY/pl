/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 // time complexity O(klogN) N is total number of ListNode 
 // space complexity is O(k)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        struct cmp{
            bool operator()(const ListNode* a, const ListNode *b){
                return a->val>b->val;
            }
        };
        
        priority_queue<ListNode*,vector<ListNode*>, cmp> pq;
        
        for(auto &l :lists){
            if(l){
                pq.push(l);
            }
        }
        
        ListNode *dummy = new ListNode(-1);
        ListNode *pre=dummy;
        
        while(!pq.empty()){
            ListNode *tmp=pq.top();
            pq.pop();
            
            if(tmp->next){
                pq.push(tmp->next);
            }
            
            pre->next=tmp;
            pre=pre->next;
        }
        
        return dummy->next;
    }
};