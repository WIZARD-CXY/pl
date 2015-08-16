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
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode *sortedListToBST(ListNode *head) {
        // write your code here
        if(head==NULL){
            return NULL;
        }
        
        ListNode *cur=head;
        int len=0;
        while(cur){
            cur=cur->next;
            len++;
        }
        
        return helper(head,0,len-1);
    }
    // move head pointer
    TreeNode* helper(ListNode* &head,int start, int end){
        if(start>end){
            return NULL;
        }
        
       // in-order traveral
       int mid=(start+end)>>1;
       TreeNode *left=helper(head,start,mid-1);
       
       TreeNode *root=new TreeNode(head->val);
       root->left=left;
       head=head->next;
       
       root->right=helper(head,mid+1,end);
       
       return root;
    }
};



