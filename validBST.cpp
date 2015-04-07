class Solution {
public:
    bool check(TreeNode *node, long leftVal, long rightVal)
    {
        if (node == NULL)
            return true;
            
        if((node->left==NULL || node->right==NULL )&& (node->val == INT_MIN || node->val == INT_MAX)){
            return true;
        }
            
        return leftVal < node->val && node->val < rightVal && check(node->left, leftVal, node->val) &&
            check(node->right, node->val, rightVal);
    }
    
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return check(root, INT_MIN, INT_MAX);        
    }
};
