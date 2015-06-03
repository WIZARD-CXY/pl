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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }
    
    TreeNode* helper(vector<int>& nums,int b, int e){
        if(b>e){
            return NULL;
        }
        int mid = (b+e)/2;
        
        TreeNode *root= new TreeNode(nums[mid]);
        root->left=helper(nums, b, mid-1);
        root->right=helper(nums,mid+1,e);
        
        return root;
    }
};