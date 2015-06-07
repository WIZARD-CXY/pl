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
    int maxSum=INT_MIN;
    int maxPathSum(TreeNode* root) {
        pathSum(root);
        
        return maxSum;
    }
    
    int pathSum(TreeNode *root){
        if(root==NULL){
            return 0;
        }
        
        int lsum=pathSum(root->left);
        int rsum=pathSum(root->right);
        
        int sum=root->val;
        
        if(lsum>0){
            sum+=lsum;
        }
        
        if(rsum>0){
            sum+=rsum;
        }
         maxSum=max(maxSum,sum);
         
         return max(lsum,rsum)>0?max(lsum,rsum)+root->val:root->val;
        
    }
};su