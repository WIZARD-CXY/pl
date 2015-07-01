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
        stack<TreeNode*> s;
        s.push(root->left);
        s.push(root->right);
        
        while(!s.empty()){
            TreeNode *a = s.top();
            s.pop();
            TreeNode *b = s.top();
            s.pop();
            if(a== NULL && b==NULL){
                continue;
            } else if(a== NULL || b==NULL){
                return false;
            } else if(a->val != b->val){
                return false;
            }else if(a->val == b->val){
                s.push(a->left);
                s.push(b->right);
                s.push(a->right);
                s.push(b->left);
            }
            
        }
        return true;
        
    }
};