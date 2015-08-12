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
 * Example of iterate a tree:
 * Solution iterator = Solution(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
 */
class Solution {
public:
    //@param root: The root of binary tree.
    Solution(TreeNode *root) {
        // write your code here
        pushroot(root);
    }

    //@return: True if there has next node, or false
    bool hasNext() {
        // write your code here
        return !ss.empty();
    }
    
    //@return: return next node
    TreeNode* next() {
        // write your code here
        TreeNode *tmp=ss.top();
        ss.pop();
        pushroot(tmp->right);
        return tmp;
    }
    
    stack<TreeNode*> ss;
    
    void pushroot(TreeNode *root){
        while(root){
            ss.push(root);
            root=root->left;
        }
    }
};
