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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> qq;
        
        vector<vector<int> > res;
        if(root==NULL){
            return res;
        }
        
        qq.push(root);
        while(!qq.empty()){
            int count=qq.size();
            
            vector<int> tmp;
            for(int i=0; i<count; i++){
                TreeNode* x=qq.front();
                qq.pop();
                tmp.push_back(x->val);
                
                if(x->left){
                    qq.push(x->left);
                }
                
                if(x->right){
                    qq.push(x->right);
                }
            }
            res.push_back(tmp);
        }
        
        return res;
    }
};