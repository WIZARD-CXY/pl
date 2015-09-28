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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> pre;
        vector<int> res;
        
        inorder(root,pre);
        
        auto lowb=lower_bound(pre.begin(),pre.end(),target);
        int l,r;
        
        l=lowb-pre.begin()-1;
        r=lowb-pre.begin();
        
        
        while(k--){
            
            if(l<0){
                res.push_back(pre[r]);
                r++;
            }else if(r>=pre.size()){
                res.push_back(pre[l]);
                l--;
            }else{
                if(abs(pre[l]-target)<abs(pre[r]-target)){
                    res.push_back(pre[l]);
                    l--;
                }else{
                    res.push_back(pre[r]);
                    r++;
                }
            }
        }
        
        return res;
        
    }
    
    void inorder(TreeNode *root,vector<int> &pre){
        if(root){
            inorder(root->left,pre);
            pre.push_back(root->val);
            inorder(root->right,pre);
        }
    }
};