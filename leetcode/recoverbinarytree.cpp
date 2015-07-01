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
    TreeNode *pre = NULL;
    void recoverTree(TreeNode* root) {
        TreeNode *large=NULL, *small=NULL;
        if(root==NULL){
            return;
        }
        inorder(root,small,large);
        swap(small->val,large->val);
    }
    
    void inorder(TreeNode *root,TreeNode* &small, TreeNode* &large){
        if(root==NULL){
            return;
        }
        
        inorder(root->left,small,large);
        
        if(pre!=NULL && pre->val>root->val){
            if(large == NULL){
                large=pre;//only record once
            }
            small=root;//always update small
        }
        pre=root;
        
        inorder(root->right,small,large);
    }
};