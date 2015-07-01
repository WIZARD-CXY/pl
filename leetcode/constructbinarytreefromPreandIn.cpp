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
    template<typename Iter>
    TreeNode* helper(Iter pFirst, Iter pLast, Iter iFirst, Iter iLast){
        if(pFirst==pLast){
            return NULL;
        }
        if(iFirst==iLast){
            return NULL;
        }
        
        Iter iRoot=find(iFirst,iLast,*pFirst);
        TreeNode *root = new TreeNode(*pFirst);
        
        int leftsize=iRoot-iFirst;
        
        root->left=helper(pFirst+1, pFirst+leftsize+1, iFirst, iRoot);
        root->right=helper(pFirst+leftsize+1, pLast, iRoot+1, iLast);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder.begin(),preorder.end(),inorder.begin(),inorder.end());
    }
};