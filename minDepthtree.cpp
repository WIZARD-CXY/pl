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
    int minD=INT_MAX;
    int minDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        dfs(root,0);
        
        return minD;
    }
    
    void dfs(TreeNode *root,int curD){
        curD++;
        
        if(curD>minD){
            // prune, if the current depth is larger than minD no need to go deeper
            return;
        }
    
        if(root->left==NULL && root->right==NULL){
            if(curD<minD){
                minD=curD;
            }
        }
        
        if(root->left){
            dfs(root->left,curD);
        }
        if(root->right){
            dfs(root->right,curD);
        }
        
    }
};