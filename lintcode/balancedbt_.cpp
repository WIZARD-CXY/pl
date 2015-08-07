/**
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
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        // write your code here
        if(checkH(root)==-1){
            return false;
        }else{
            return true;
        }
    }
    
    int checkH(TreeNode *root){
        if(root==NULL){
            return 0;
        }
        
        int lh=checkH(root->left);
        if(lh==-1){
            return -1;// left subtree is imba
        }
        
        int rh=checkH(root->right);
        
        if(rh==-1){//right sub tree is imba
            return -1;
        }
        
        if(abs(lh-rh)>1){
            return -1;
        }else{
            return max(rh,lh)+1;
        }
    }
};
