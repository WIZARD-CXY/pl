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
    int closestValue(TreeNode* root, double target) {
        if(root==NULL){
            return 0;
        }
        
        int res=root->val;
        while(root){
            if(abs(root->val-target)<abs(res-target)){
                res=root->val;
            }
            root=root->val>target?root->left:root->right;
        }
        
        return res;
    }
};