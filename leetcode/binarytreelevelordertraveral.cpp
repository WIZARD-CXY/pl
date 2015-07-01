/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        queue<TreeNode*> q;
        vector<int> temp;
        vector<vector<int> > res;
        if(root == NULL){
            return res;
        }
        
        q.push(root);
        int count=1; // indicate the unvisted node number
        
        while(!q.empty()){
            TreeNode *node = q.front();
            int val = node->val;
            q.pop();
            
            temp.push_back(val);
            count--;
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
            
            if(count==0){
                res.push_back(temp);
                temp.clear();
                count=q.size();
            }
            
        }
        return res;
    }
};