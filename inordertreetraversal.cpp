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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> ss;
        
        TreeNode *p=root;
        
        while(!ss.empty() || p!=NULL){
            if(p!=NULL){
                ss.push(p);
                p=p->left;
            }else{
                TreeNode *temp = ss.top();
                ss.pop();
                res.push_back(temp->val);
                p=temp->right;
                
            }
        }
        return res;
    }
};