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
    int kthSmallest(TreeNode* root, int k) {
        int idx=0;
        int res;
        helper(root,idx,res,k);
        
        return res;
    }
    void helper(TreeNode *root, int &idx, int &res,int k){
        if(root==NULL){
            return;
        }
        helper(root->left,idx,res,k);
        idx++;
        if(idx==k){
            res=root->val;
            return;
        }
        if(idx>k){
            return;
        }
        
        helper(root->right,idx,res,k);
        
    }
};