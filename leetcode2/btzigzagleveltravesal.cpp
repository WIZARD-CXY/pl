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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > res;
        vector<int> path;
        
        if(root==NULL){
            return res;
        }
        
        queue<TreeNode*> qq;
        qq.push(root);
        int level=1;
        int count=1;
        
        while(!qq.empty()){
            TreeNode *tmp=qq.front();
            qq.pop();
            if(level&1){
                path.push_back(tmp->val);
            }else{
                path.insert(path.begin(),tmp->val);
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
                res.push_back(path);
                path.clear();
                level++;
            }
        }
        return res;
    }
};