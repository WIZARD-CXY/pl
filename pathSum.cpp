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
    bool flag=false;
     
    void dfs(TreeNode *node, int curSum, int sum) {
         
        if(curSum + node->val == sum) {
            if(node->left == NULL && node->right == NULL) {
                flag = true;
                return;
            }
        }
        if(node->left != NULL && !flag) {
            dfs(node->left, curSum+node->val,sum);
        }
        if(node->right != NULL && !flag) {
            dfs(node->right, curSum+node->val,sum);
        }
         
    }
    bool hasPathSum(TreeNode *root, int sum) {
      
      if(root == NULL)
          return false;
      else
        dfs(root, 0, sum);
        
      return flag;
    }
};