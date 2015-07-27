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
        int depth;
        
        return helper(root, depth);
    }
    
    bool helper(TreeNode *root, int &depth){
        if(root==NULL){
            depth=0;
            return true;
        }
        
        int ld,rd;
        
        bool res=helper(root->left,ld) && helper(root->right,rd);
        depth=max(ld,rd)+1;
        
        if(res){
            // left sub tree is balanced and right sub tree is balanced
            if(abs(ld-rd)<=1){
                return true;
            }
        }
        
        return false;
    }
};
