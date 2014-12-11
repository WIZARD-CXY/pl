/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > res;
        
        if(root==NULL){
            return res;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        int count=1;
        vector<int> ivec;
        
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            
            int value= node->val;
            
            count--;
            ivec.push_back(value);
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
            
            if(count==0){
                res.push_back(ivec);
                ivec.clear();
                count=q.size();
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};