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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        
        if(root==NULL){
            return res;
        }
        string path="";
        dfs(root,res,path);
        
        return res;
    }
    
    void dfs(TreeNode *root, vector<string> &res, string path){
        if(path.empty()){
            path+=to_string(root->val);
        }else{
            path+="->"+to_string(root->val);
        }
        
        if(root->left==NULL && root->right ==NULL){
            res.push_back(path);
            return;
        }
        
        //dfs on the left sub tree
        if(root->left){
            dfs(root->left,res,path);
        }
        
        //dfs on the right sub tree
        if(root->right){
            dfs(root->right,res,path);
        }
        
    }
};