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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        
        if(root==NULL){
            return res;
        }
        
        queue<TreeNode*> qq;
        
        qq.push(root);
        
        while(!qq.empty()){
            int count=qq.size();
            
            for(int i=0; i<count; i++){
                TreeNode *x=qq.front();
                qq.pop();
                if(i==0){
                    res.push_back(x->val);
                }
                if(x->right){
                    qq.push(x->right);
                }
                
                if(x->left){
                    qq.push(x->left);
                }
            }
        }
        
        return res;
    }
};
