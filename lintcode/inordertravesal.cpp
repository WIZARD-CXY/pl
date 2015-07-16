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
    /**
     * @param root: The root of binary tree.
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> res;
        if(root==NULL){
            return res;
        }
        
        stack<TreeNode*> ss;
        
        TreeNode* p=root;
        while(!ss.empty() || p!=NULL){
            if(p!=NULL){
                ss.push(p);
                p=p->left;
            }else{
                TreeNode *temp=ss.top();
                ss.pop();
                res.push_back(temp->val);
                p=temp->right;
            }
        }
        
        return res;
    }
};
