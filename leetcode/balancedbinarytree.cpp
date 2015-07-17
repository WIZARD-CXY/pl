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
    bool isBalanced(TreeNode* root) {
        int d=0;
        return helper(root,d);
    }
    bool helper(TreeNode *root, int &d){
        if(root==NULL){
            d=0;
            return true;
        }
        //root->left depth, root->right depth
        int ld,rd;
        if(helper(root->left,ld) && helper(root->right,rd)){
            //if left sub tree is balanced and right is
            if(abs(ld-rd)<=1){
                d=max(ld,rd)+1;
                return true;
            }
        }
        
        return false;
    }
};