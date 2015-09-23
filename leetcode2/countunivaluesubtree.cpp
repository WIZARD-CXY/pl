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
    int countUnivalSubtrees(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        
        int count=0;
        
        helper(root,count);
        
        return count;
    }
    bool helper(TreeNode* root, int &count){
        if(root==NULL){
            return true;
        }
        
        bool lres=helper(root->left,count);
        bool rres=helper(root->right,count);
        
        if(lres && rres){
            //left substree and right subtree is unival
            if((root->left==NULL || root->left->val==root->val) && (root->right==NULL || root->right->val==root->val)){
                //check the root and left subtree and right subtree
                count++;
                return true;
            }
        }
        
        return false;
    }
};