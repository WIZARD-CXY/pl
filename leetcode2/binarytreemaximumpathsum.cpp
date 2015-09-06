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
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        
        // a root started subtree max
        pathsum(root,res);
        
        return res;
    }
    int pathsum(TreeNode *root, int &res){
        if(root==NULL){
            return 0;
        }
        int lmax=pathsum(root->left,res);
        int rmax=pathsum(root->right,res);
        
        int sum=root->val;
        if(lmax>0){
            sum+=lmax;
        }
        
        if(rmax>0){
            sum+=rmax;
        }
        
        res=max(res,sum);
        
        if(lmax<0 && rmax <0){
            return root->val;
        }else{
            return max(lmax,rmax)+root->val;
        }
    }
};