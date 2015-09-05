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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> qq;
        vector<vector<int> > res;
        vector<int> path;
        
        if(root==NULL){
            return res;
        }
        
        qq.push(root);
        int count=1;
        
        while(!qq.empty()){
            TreeNode *tmp=qq.front();
            qq.pop();
            count--;
            path.push_back(tmp->val);
            
            if(tmp->left){
                qq.push(tmp->left);
            }
            
            if(tmp->right){
                qq.push(tmp->right);
            }
            
            if(count==0){
                count=qq.size();
                res.push_back(path);
                path.clear();
            }
        }
        reverse(res.begin(),res.end());
        
        return res;
    }
};