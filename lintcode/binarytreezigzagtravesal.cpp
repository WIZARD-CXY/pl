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
     * @return: A list of lists of integer include 
     *          the zigzag level order traversal of its nodes' values 
     */
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        // write your code here
        vector<vector<int> > res;
        
        if(root==NULL){
            return res;
        }
        
        queue<TreeNode*> qq;
        qq.push(root);
        int count=1;
        int level=1;
        vector<int> tmp;
        
        while(!qq.empty()){
            TreeNode* p=qq.front();
            qq.pop();
            tmp.push_back(p->val);
            
            count--;
            if(p->left){
                qq.push(p->left);
            }
            if(p->right){
                qq.push(p->right);
            }
            
            if(count==0){
                if(level&1){
                    res.push_back(tmp);
                }else{
                    reverse(tmp.begin(),tmp.end());
                    res.push_back(tmp);
                }
                tmp.clear();
                level++;
                count=qq.size();
            }
        }
        
        return res;
    }
};
