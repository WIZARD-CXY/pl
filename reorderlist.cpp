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
    void reorderList(ListNode *head) {
        if(head==NULL){
            return;
        }
        
        vector<ListNode*> res;
        
        ListNode *temp=head;
        
        while(temp){
            res.push_back(temp);
            temp=temp->next;
        }
        
        int begin=0;
        int end=res.size()-1;
        
        while(begin<end){
            res[begin]->next=res[end];
            res[end--]->next=res[++begin];
        }
        res[begin]->next=NULL;
        
    }
};