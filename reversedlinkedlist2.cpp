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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        vector<ListNode*> range(n - m + 1);
        
        ListNode* iter = head;
        for(int i = 1; i < m; ++i)
            iter = iter->next;
            
        for(int i = m, j = 0; i <= n; ++i, ++j)
        {
            range[j] = iter;
            iter = iter->next;
        }
        
        for(size_t i = 0; i < range.size() / 2; ++i)
            swap(range[i]->val, range[range.size() - i - 1]->val);
        
        return head;
    }
};