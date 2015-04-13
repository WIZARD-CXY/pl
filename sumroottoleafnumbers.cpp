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
    int sum=0;
    
    void dfs(TreeNode *node, int cur){
        if(node->left==NULL && node->right == NULL){
            cur=cur*10+node->val;
            sum+=cur;
            return;
        }
        
        if(node->left){
            dfs(node->left, cur*10+node->val);
        }
        if(node->right){
            dfs(node->right,cur*10+node->val);
        }
    }
    int sumNumbers(TreeNode *root) {
        if(root==NULL){
            return 0;
        }
        
        dfs(root,0);
        
        return sum;
        
    }
};