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
    /**
     * @param root: The root of binary tree.
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        // write your code here
        vector<vector<int> > res;
        
        if(root==NULL){
            return res;
        }
        
        queue<TreeNode*> qq;
        
        qq.push(root);
        int count=1;
        vector<int> level;
        
        while(!qq.empty()){
            TreeNode *temp=qq.front();
            qq.pop();
            level.push_back(temp->val);
            
            count--;
            if(temp->left){
                qq.push(temp->left);
            }
            
            if(temp->right){
                qq.push(temp->right);
            }
            
            if(count==0){
                res.push_back(level);
                level.clear();
                count=qq.size();
            }
        }
        
        return res;
    }
};

