/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    struct cmp{
        bool operator()(const ListNode *a, const ListNode *b){
            return a->val > b->val;
        }
    };
    ListNode *mergeKLists(vector<ListNode*> &lists) {
        // write your code here
        ListNode *dummy = new ListNode(-1);
        ListNode *pre=dummy;
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        
        // insert not-null head into pq; 
        for(auto node : lists){
            if(node){
                pq.push(node);
            }
        }
        
        // pop back
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