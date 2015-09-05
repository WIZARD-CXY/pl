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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL){
            return false;
        }
        bool res=false;
        
        dfs(root,sum,res);
        
        return res;
    }
    
    void dfs(TreeNode *root, int sum, bool &res){
        if(res){
            //prune
            return;
        }
        
        sum-=root->val;
        if(root->left==NULL && root->right==NULL){
            if(sum==0){
                res=true;
                return;
            }
        }
        
        if(root->left){
            dfs(root->left,sum,res);
        }
        if(root->right){
            dfs(root->right,sum,res);
        }
    }
};