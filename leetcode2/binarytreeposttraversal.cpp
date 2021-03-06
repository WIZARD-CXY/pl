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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> ss;
        vector<int> res;
        
        if(root==NULL){
            return res;
        }
        
        unordered_set<TreeNode*> s;
        
        ss.push(root);
        
        while(!ss.empty()){
            TreeNode *tmp=ss.top();
            ss.pop();
            
            if(s.find(tmp)!=s.end()){
                res.push_back(tmp->val);
                continue;
            }
            
            s.insert(tmp);
            
            //push stack sequence is root, right, left
            ss.push(tmp);
            if(tmp->right){
                ss.push(tmp->right);
            }
            
            if(tmp->left){
                ss.push(tmp->left);
            }
        }
        
        return res;
    }
};