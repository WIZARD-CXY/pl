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
    vector<vector<int> > paths;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root==NULL){
            return paths;
        }
        vector<int> path;
        dfs(root,sum,path);
        
        return paths;
    }
    void dfs(TreeNode* root, int sum, vector<int> &path){
        if(root==NULL){
            return;
        }
        
        path.push_back(root->val);
        
        if(root->left==NULL && root->right ==NULL){
            if(sum==root->val){
                paths.push_back(path);
            }
        }
        dfs(root->left,sum-root->val,path);
        dfs(root->right,sum-root->val,path);
        
        path.pop_back();
    }
};