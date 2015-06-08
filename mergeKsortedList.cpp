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
        bool operator()(const ListNode *a, const ListNode *b) const{
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        
        ListNode *dummy = new ListNode(-1),*pre=dummy;
        
        for(int i=0; i< lists.size(); i++){
            if(lists[i]){
                pq.push(lists[i]);
            }
        }
        
        while(!pq.empty()){
            ListNode *node = pq.top();
            pq.pop();
            
            if(node->next){
                pq.push(node->next);
            }
            pre->next=node;
            pre=node;
        }
        
        pre->next=NULL;
        return dummy->next;
        
    }
    
};