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
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode *root) {
        // write your code here
        // use LONG_MIN and LONG_MAX here avoid single node whose val is INT_MIN
        // or INT_MAX
        return helper(root,LONG_MIN,LONG_MAX);
    }
    
    bool helper(TreeNode *root,long long low, long long high){
        if(root==NULL){
            return true;
        }
        if(root->val>=high || root->val<=low){
            return false;
        }
        return helper(root->left,low,root->val) && helper(root->right,root->val,high);
    }
};
