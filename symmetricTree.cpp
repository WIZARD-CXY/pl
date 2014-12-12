/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if(root==NULL){
            return true;
        }
        return test(root->left,root->right);
    }
    bool test(TreeNode* a, TreeNode* b){
        if(a == NULL && b == NULL){
            return true;
        }else if (a==NULL || b==NULL){
            return false;
        }else if(a->val != b->val){
            return false;
        }else if (test(a->left,b->right) && test(a->right,b->left)){
            return true;
        }else{
            return false;
        }
        
    }
};