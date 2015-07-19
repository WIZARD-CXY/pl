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
     * @return: An integer
     */
    int maxDepth(TreeNode *root) {
        // write your code here
        if(root==NULL){
            return 0;
        }
        
        int ld=maxDepth(root->left);
        int rd=maxDepth(root->right);
        
        return max(ld,rd)+1;
    }
};
