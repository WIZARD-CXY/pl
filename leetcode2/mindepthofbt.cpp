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
    int minDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int res=INT_MAX;
        
        dfs(root,res,0);
        
        return res;
    }
    void dfs(TreeNode *root, int &res, int depth){
        depth++;
        if(root->left==NULL && root->right==NULL){
            if(depth<res){
                res=depth;
            }
            return;
        }
        
        if(depth>res){
            //prune
            return;
        }
        
        if(root->left){
            dfs(root->left,res,depth);
        }
        
        if(root->right){
            dfs(root->right,res,depth);
        }
    }
};