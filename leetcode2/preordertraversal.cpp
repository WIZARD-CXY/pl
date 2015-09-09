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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==NULL){
            return res;
        }
        
        stack<TreeNode*> ss;
        ss.push(root);
        
        while(!ss.empty()){
            TreeNode *tmp=ss.top();
            ss.pop();
            
            res.push_back(tmp->val);
            if(tmp->right){
                ss.push(tmp->right);
            }
            
            if(tmp->left){
                ss.push(tmp->left);
            }
        }
        return res;
    }
};