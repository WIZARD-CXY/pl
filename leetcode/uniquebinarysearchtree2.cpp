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
        return createTree(1,n);
    }
    
    vector<TreeNode*> createTree(int st,int end){
        vector<TreeNode*> res;
        if(st>end){
            res.push_back(NULL);
            return res;
        }
        
        for(int k=st; k<=end; k++){
            //k as root
            vector<TreeNode*> left = createTree(st,k-1);
            vector<TreeNode*> right= createTree(k+1,end);
            
            for(int i=0; i<left.size(); i++){
                for(int j=0; j<right.size(); j++){
                    TreeNode* root= new TreeNode(k);
                    root->left=left[i];
                    root->right=right[j];
                    
                    res.push_back(root);
                }
            }
        }
        
        return res;
    }
};