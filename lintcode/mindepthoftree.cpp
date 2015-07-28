/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int minD=INT_MAX;
    int minDepth(TreeNode *root) {
        // write your code here
        if(root==NULL){
            return 0;
        }
        dfs(root,0);
        
        return minD;
    }
    
    void dfs(TreeNode *root, int curD){
        curD++;
        if(curD>minD){
            return;
        }
        
        if(root->left==NULL && root->right==NULL){
            //reach the leaf node
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
