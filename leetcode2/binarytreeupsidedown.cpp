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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(root==NULL || root->left==NULL){
            //base case
            return root;
        }
    
        TreeNode *l=root->left,*r=root->right;
        
        TreeNode *newroot=upsideDownBinaryTree(root->left);
        //l as new root
        l->left=r;
        l->right=root;
        
        root->left=NULL;
        root->right=NULL;
        
        return newroot;
    }
};