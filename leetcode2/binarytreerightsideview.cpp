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
        int count=1;
        
        while(!qq.empty()){
            TreeNode *tmp=qq.front();
            qq.pop();
            if(count==1){
                //last one 
                res.push_back(tmp->val);
            }
            count--;
            
            if(tmp->left){
                qq.push(tmp->left);
            }
            if(tmp->right){
                qq.push(tmp->right);
            }
            
            if(count==0){
                count=qq.size();
            }
        }
        
        return res;
    }
};