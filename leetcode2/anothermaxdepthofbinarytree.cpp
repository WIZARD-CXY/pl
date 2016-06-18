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
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        // use pre-order dfs search
        helper(root,0);
        
        return maxh;
    }
    
    void helper(TreeNode* root, int curh){
        if(root){
            curh++;
            if(curh>maxh){
                maxh=curh;
            }
            
            helper(root->left,curh);
            helper(root->right,curh);
        }
    }
    int maxh=0;
};