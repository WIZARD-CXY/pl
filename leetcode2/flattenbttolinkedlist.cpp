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
    void flatten(TreeNode* root) {
        if(root==NULL){
            return;
        }
        stack<TreeNode*> ss;
        ss.push(root);
        
        while(!ss.empty()){
            TreeNode *tmp=ss.top();
            ss.pop();
            
            if(tmp->right){
                ss.push(tmp->right);
            }
            
            if(tmp->left){
                ss.push(tmp->left);
            }
            // disable the tmp->left pointer
            tmp->left=NULL;
            if(!ss.empty()){
                tmp->right=ss.top();
            }
            
        }
    }
};