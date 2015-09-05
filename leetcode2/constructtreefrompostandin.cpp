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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder.begin(),inorder.end(),postorder.begin(),postorder.end());
    }
    
    TreeNode* helper(auto ib, auto ie, auto pb, auto pe){
        if(ib==ie){
            return NULL;
        }
        
        TreeNode *root=new TreeNode(*(pe-1));
        auto rootin=find(ib,ie,*(pe-1));
        
        int leftsize=rootin-ib;
        root->left=helper(ib,rootin,pb,pb+leftsize);
        root->right=helper(rootin+1,ie,pb+leftsize,pe-1);
        
        return root;
    }
};