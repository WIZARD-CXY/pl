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
    TreeNode* helper(Iter iF, Iter iL, Iter pF, Iter pL){
        if(iF==iL){
            return NULL;
        }
        if(pF==pL){
            return NULL;
        }
        
        Iter iRoot=find(iF,iL,*(pL-1));
        
        TreeNode *root=new TreeNode(*(pL-1));
        int leftsize = iRoot-iF; 
        
        root->left=helper(iF,iRoot,pF,pF+leftsize);
        root->right=helper(iRoot+1,iL,pF+leftsize,pL-1);
        
        return root;
        
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder.begin(),inorder.end(),postorder.begin(),postorder.end());
    }
};