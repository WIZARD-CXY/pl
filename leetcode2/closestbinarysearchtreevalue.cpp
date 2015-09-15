class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        if(root==NULL){
        	return INT_MAX;
        }

        int a=root->val;
        auto kid=(target<a)?root->left:root->right;

        if(kid==NULL){
        	return a;
        }

        int b=closestValue(kid,target);
        return abs(a-target) <abs(b-target)?a:b;
    }
};