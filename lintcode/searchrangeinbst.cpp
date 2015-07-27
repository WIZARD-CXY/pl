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
     * @param root: The root of the binary search tree.
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    vector<int> searchRange(TreeNode* root, int k1, int k2) {
        // write your code here
        // use in order travesal
        vector<int> res;
        
        preorder(root,res,k1,k2);
        
        return res;
    }
    
    void preorder(TreeNode *root, vector<int> &res, int k1, int k2){
        if(root){
            if(root->val>k1){
                // if root->val <k1, need not to travesal the left
               preorder(root->left,res,k1,k2);
            }
            
            if(root->val>=k1 && root->val<=k2){
                res.push_back(root->val);
            }
            
            if(root->val<k2){
                // if root->val >k2 , need not to travesal to the right
                preorder(root->right,res,k1,k2);
            }
        }
    }
};
