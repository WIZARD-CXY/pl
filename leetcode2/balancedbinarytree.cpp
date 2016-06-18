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
    bool isBalanced(TreeNode* root) {
        
        if(check(root)==-1){
            return false;
        }
        
        return true;
    }
    int check(TreeNode *root){
        if(root==NULL){
            return 0;
        }
        
        int lh=check(root->left);
        if(lh==-1){
            return -1;
        }
        
        int rh=check(root->right);
        if(rh==-1){
            return -1;
        }
        
        if(abs(lh-rh)>1){
            return -1;
        }
        
        return max(lh,rh)+1;
    }
};