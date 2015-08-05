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
public:
    /**
     * @paramn n: An integer
     * @return: A list of root
     */
    vector<TreeNode *> generateTrees(int n) {
        // write your code here
        return helper(1,n);
    }
    
    vector<TreeNode*> helper(int start, int end){
        vector<TreeNode*> res;
        if(start>end){
            res.push_back(NULL);
            return res;
        }
        
        //post order travesal
        for(int r=start; r<=end; r++){
            // r as root
            vector<TreeNode*> left=helper(start,r-1);
            vector<TreeNode*> right=helper(r+1,end);
            
            // travesal left sub tree and right sub tree
            for(int i=0; i<left.size(); i++){
                for(int j=0; j<right.size(); j++){
                    TreeNode *root= new TreeNode(r);
                    root->left=left[i];
                    root->right=right[j];
                    
                    res.push_back(root);
                }
            }
        }
        
        return res;
    }
};
