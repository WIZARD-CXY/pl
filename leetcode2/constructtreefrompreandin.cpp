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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder.begin(),preorder.end(),inorder.begin(),inorder.end());
    }
    
    TreeNode* helper(auto pb, auto pe, auto ib, auto ie){
        if(pb>=pe){
            return NULL;
        }
        
        TreeNode* root=new TreeNode(*pb);
        auto rootin=find(ib,ie,*pb);
        int leftsize=rootin-ib;
        root->left=helper(pb+1,pb+leftsize+1,ib,rootin);
        root->right=helper(pb+leftsize+1,pe,rootin+1,ie);
        
        return root;
    }
};