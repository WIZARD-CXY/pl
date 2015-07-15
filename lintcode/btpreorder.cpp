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
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> res;
        if(root==NULL){
            return res;
        }
        
        stack<TreeNode*> ss;
        ss.push(root);
        while(!ss.empty()){
            TreeNode *temp=ss.top();
            ss.pop();
            res.push_back(temp->val);
            if(temp->right){
                ss.push(temp->right);
            }
            
            if(temp->left){
                 ss.push(temp->left);
            }
           
        }
        
        return res;
    }
};

