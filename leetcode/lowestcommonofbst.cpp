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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *cur=root;
        
        int minV=min(p->val,q->val);
        int maxV=max(p->val,q->val);
        
        while(cur){
            if(cur->val>=minV && cur->val <=maxV){
                return cur;
            }else if(cur->val > maxV){
                cur=cur->left;
            }else{
                cur=cur->right;
            }
        }
        
        return NULL;
    }
};