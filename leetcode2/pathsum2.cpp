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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > res;
        vector<int> path;
        
        if(root==NULL){
            return res;
        }
        helper(res,path,root,sum);
        
        return res;
    }
    
    void helper(vector<vector<int> > &res, vector<int> &path, TreeNode *root, int sum){
        sum-=root->val;
        path.push_back(root->val);
        
        if(root->left==NULL && root->right==NULL){
            if(sum==0){
                res.push_back(path);
            }
            path.pop_back();
            return;
        }
        
        if(root->left){
            helper(res,path,root->left,sum);
        }
        
        if(root->right){
            helper(res,path,root->right,sum);
        }
        path.pop_back();
    }
};