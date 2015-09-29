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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(root==NULL || p==NULL){
            return NULL;
        }
        TreeNode *can=NULL;
        while(root){
            if(root->val>p->val){
                can=root;
                root=root->left;
            }else{
                root=root->right;
            }
        }
        
        return can;
    }
};