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
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            // search to leaf node but not find
            return NULL;
        }
        
        if(root==p || root ==q){
            // root == either p or q
            return root;
        }
        // search left subtree or right subtree
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        
        //if find
        if(left && right){
            // common parent
            return root;
        }
        
        return left?left:right; 
    }
};