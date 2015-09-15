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
    int countNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        
        TreeNode *lroot=root;
        TreeNode *rroot=root;
        int lh=0,rh=0;
        while(lroot){
            lh++;
            lroot=lroot->left;
        }
        while(rroot){
            rh++;
            rroot=rroot->right;
        }
        
        if(lh==rh){
            return (1<<lh)-1;
        }
        else{
            return 1+countNodes(root->left)+countNodes(root->right);
        }
    }
};