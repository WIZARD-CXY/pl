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
    int sumNumbers(TreeNode* root) {
        int sum=0;
        helper(root,0,sum);
        
        return sum;
    }
    
    void helper(TreeNode *root, int parsum, int& totalsum){
        if(root==NULL){
            return;
        }
        
        parsum=parsum*10+root->val;
        
        if(root->left==NULL && root->right==NULL){
            totalsum+=parsum;
            return;
        }
        helper(root->left,parsum,totalsum);
        helper(root->right,parsum,totalsum);
    }
};