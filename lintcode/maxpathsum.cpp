/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxsum=INT_MIN;
    int maxPathSum(TreeNode *root) {
        // write your code here
        pathsum(root);
        
        return maxsum;
    }
    
    int pathsum(TreeNode *root){
        if(root==NULL){
            return 0;
        }
        
        int lsum=pathsum(root->left);
        int rsum=pathsum(root->right);
        
        int sum=root->val;
        if(lsum>0){
            sum+=lsum;
        }
        if(rsum>0){
            sum+=rsum;
        }
        
        maxsum=max(sum,maxsum);
        
        //left to root or right to root or only root value
        //determination is which one is larger
        if(lsum<0 && rsum<0){
            return root->val;
        }else{
            return root->val+max(lsum,rsum);
        }
    }
};
