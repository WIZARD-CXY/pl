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
        if(root==NULL){
            return root;
        }
        int minVal=min(p->val,q->val);
        int maxVal=max(p->val,q->val);
        if(root->val >= minVal && root->val <= maxVal){
            return root;
        }else if(root->val > maxVal){
            return lowestCommonAncestor(root->left,p,q);
        }else{
            return lowestCommonAncestor(root->right,p,q);
        }
        
    }
};