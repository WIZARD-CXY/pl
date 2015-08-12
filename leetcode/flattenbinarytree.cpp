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
            TreeNode *p =ss.top();
            ss.pop();
            
            if(p->right){
                ss.push(p->right);
            }
            
            if(p->left){
                ss.push(p->left);
            }
            
            p->left=NULL;
            if(!ss.empty()){
                p->right=ss.top();
            }
        }
    }
};