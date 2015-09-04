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
    void recoverTree(TreeNode* root) {
        TreeNode *pre=NULL;
        TreeNode *large=NULL;
        TreeNode *small=NULL;
        
        helper(root,pre,large,small);
        
        if(large!=NULL && small != NULL){
            swap(large->val,small->val);
        }
        
    }
    
    void helper(TreeNode *root,TreeNode* &pre, TreeNode* &large, TreeNode* &small){
        if(root){
            helper(root->left,pre,large,small);
            
            if(pre!=NULL && root->val<pre->val){
                if(large==NULL){
                    large=pre;
                }
                small=root;
            }
            pre=root;
            
            helper(root->right,pre,large,small);
        }
    }
};