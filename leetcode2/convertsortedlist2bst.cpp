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
        ListNode *cur=head;
        int len=0;
        
        while(cur){
            len++;
            cur=cur->next;
        }
        
        return helper(head,0,len-1);
    }
    
    TreeNode *helper(ListNode *&head,int start,int end){
        if(head==NULL || start>end){
            return NULL;
        }
        
        // recursive call in left subtree
        int mid=start+((end-start)>>1);
        TreeNode *left=helper(head,start,mid-1);
        TreeNode *root=new TreeNode(head->val);
        root->left=left;
        head=head->next;
        TreeNode *right=helper(head,mid+1,end);
        root->right=right;
        
        return root;
    }
};