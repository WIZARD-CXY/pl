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
     *@param inorder : A list of integers that inorder traversal of a tree
     *@param postorder : A list of integers that postorder traversal of a tree
     *@return : Root of a tree
     */
    template<typename iter>
    TreeNode* helper(iter ib, iter ie, iter pb, iter pe){
        if(ib==ie){
            return NULL;
        }
        if(pb==pe){
            return NULL;
        }
        
        TreeNode *root = new TreeNode(*(pe-1));
        
        iter iRoot = find(ib,ie,*(pe-1));
        int leftsize = iRoot-ib;
        
        root->left=helper(ib,iRoot,pb,pb+leftsize);
        root->right=helper(iRoot+1,ie,pb+leftsize,pe-1);
        
        return root;
    }
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // write your code here
        return helper(inorder.begin(),inorder.end(),postorder.begin(),postorder.end());
    }
};
