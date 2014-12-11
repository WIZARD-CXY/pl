/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalance=true;
    
    bool isBalanced(TreeNode *root) {
        height(root);
        return isBalance;
    }
    
    int height(TreeNode* node){
        //return the max height of left subtree or right subtree
        // if the tree has already be checked out as unbalanced
        // return early
        if(!isBalance){
            return -1;
        }
        if(node==NULL){
            return 0;
        }
    
        
        int leftHeight = height(node->left);
        int rightHeight= height(node->right);
        
        if(abs(leftHeight-rightHeight)>1){
            isBalance=false;
        }
        return max(leftHeight,rightHeight)+1;
    }
};