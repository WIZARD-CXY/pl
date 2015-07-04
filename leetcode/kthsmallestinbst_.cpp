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
    int treeSize(TreeNode *node){
        //calculate the size of tree whose root is node
        if(node==NULL){
            return 0;
        }
        return 1+treeSize(node->left)+treeSize(node->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL){
            return 0;
        }
        int leftSize=treeSize(root->left);
        if(leftSize+1==k){
            return root->val;
        }else if(leftSize+1>k){
            // search the left sub-tree for kth smallest.
            return kthSmallest(root->left,k);
        }else{
            // search the right sub-tree for the (k-leftSize-1)-th smalleset
            return kthSmallest(root->right,k-leftSize-1);
        }
        
    }
};