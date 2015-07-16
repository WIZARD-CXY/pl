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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode*> ss;
        
        if(root){
            ss.push(root);
            
            while(!ss.empty()){
                TreeNode *temp=ss.top();
                res.push_back(temp->val);
                ss.pop();
                if(temp->right){
                    ss.push(temp->right);
                }
                if(temp->left){
                    ss.push(temp->left);
                }
            }
        }
        return res;
    }
    
};