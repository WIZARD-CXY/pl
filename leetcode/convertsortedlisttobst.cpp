/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int len=0;
        
        ListNode *p=head;
        
        while(p){
            len++;
            p=p->next;
        }
        
        return sortedListToBST(head,0,len-1);
    }
    
    // build the tree from bottom to top using pre-order traversal
    TreeNode* sortedListToBST(ListNode* &head, int start, int end){
        if(start>end){
            return NULL;
        }
        
        int mid=start+(end-start)/2;
        
        TreeNode *left=sortedListToBST(head,start,mid-1);
        TreeNode *root=new TreeNode(head->val);
        root->left=left;
        
        head=head->next;
        
        root->right=sortedListToBST(head, mid+1, end);
        return root;
    }
};