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
    vector<TreeNode*> generateTrees(int n) {
        return helper(1,n);
    }
    
    vector<TreeNode*> helper(int start ,int end){
        if(start>end){
            return {NULL};
        }
        
        vector<TreeNode*> res;
        
        for(int i=start; i<=end; i++){
            // post order travesal
            // use i as root, build left and right subtree recursively
            vector<TreeNode*> left=helper(start,i-1);
            vector<TreeNode*> right=helper(i+1,end);
            
            for(int j=0; j<left.size(); j++){
                for(int k=0; k<right.size(); k++){
                    TreeNode *root=new TreeNode(i);
                    root->left=left[j];
                    root->right=right[k];
                    
                    res.push_back(root);
                }
            }
        }
        
        return res;
    }
};