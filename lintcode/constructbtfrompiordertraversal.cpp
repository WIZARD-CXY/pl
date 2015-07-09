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
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // write your code here
        return helper(preorder.begin(), preorder.end(), 
                      inorder.begin(), inorder.end());
    }
    template<typename iter>
    TreeNode *helper(iter pb, iter pe, iter ib, iter ie){
        if(pb==pe){
            return NULL;
        }
        if(ib==ie){
            return NULL;
        }
        TreeNode *root = new TreeNode(*pb);
        
        iter iRoot = find(ib,ie,*pb);
        int leftSize=iRoot-ib;
        
        root->left=helper(pb+1,pb+leftSize+1,ib,iRoot);
        root->right=helper(pb+1+leftSize,pe,iRoot+1,ie);
        
        return root;
    }
};
