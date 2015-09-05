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
        vector<vector<int> > res;
        vector<int> path;
        if(root==NULL){
            return res;
        }
        
        queue<TreeNode*> qq;
        
        qq.push(root);
     
        int count=1;
        
        while(!qq.empty()){
            TreeNode *tmp=qq.front();
            qq.pop();
            path.push_back(tmp->val);
            
            count--;
            
            if(tmp->left){
                qq.push(tmp->left);
            }
            if(tmp->right){
                qq.push(tmp->right);
            }
            
            if(count==0){
                res.push_back(path);
                path.clear();
                count=qq.size();
            }
        }
        
        return res;
    }
};