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
     * @param A: Given an integer array with no duplicates.
     * @return: The root of max tree.
     */
     stack<TreeNode*> ss;
    TreeNode* maxTree(vector<int> A) {
        // write your code here
        int len=A.size();
        for(int i=0; i<len; i++){
            TreeNode *tmp = new TreeNode(A[i]);
            while(!ss.empty() && ss.top()->val<A[i]){
                tmp->left=ss.top();
                ss.pop();
            }
            //now ss.top()->val is larger thane A[i]
            
            if(!ss.empty()){
                ss.top()->right=tmp;
            }
            ss.push(tmp);
        }
        
        //stack bottom is root
        while(ss.size()>1){
            ss.pop();
        }
        
        return ss.top();
    }
    
    
};
