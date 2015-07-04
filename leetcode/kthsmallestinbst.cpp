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
    void preorder(TreeNode *node, int &idx, int k, int &res){
        if(node==NULL){
            return;
        }
        
        preorder(node->left,idx,k,res);
        idx++;
        if(idx==k){
            res=node->val;
            return;
        }
        if(idx>k){
            return;// prune
        }
        preorder(node->right,idx,k,res);
    }
    int kthSmallest(TreeNode* root, int k) {
        int res=0;
        int idx=0;
        preorder(root,idx,k,res);
        
        return res;
        
    }
};