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
     * @param A: A sorted (increasing order) array
     * @return: A tree node
     */
    TreeNode *sortedArrayToBST(vector<int> &A) {
        // write your code here
        int n=A.size();
        
        return helper(A,0,n-1);
    }
    
    TreeNode *helper(vector<int> &A, int l,int r){
        if(l>r){
            return NULL;
        }
        
        int mid=l+((r-l)>>1);
        
        TreeNode *root= new TreeNode(A[mid]);
        root->left=helper(A,l,mid-1);
        root->right=helper(A,mid+1,r);
        
        return root;
    }
};



