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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > res;
        vector<int> temp;
        
        if(root==NULL){
            return res;
        }
        
        queue<TreeNode*> qq;
     
        qq.push(root);
        
        int count=1;
        int level=1;
        
        while(!qq.empty()){
            TreeNode *p = qq.front();
            qq.pop();
            temp.push_back(p->val);
            
            count--;
            if(p->left){
                qq.push(p->left);
            }
            if(p->right){
                qq.push(p->right);
            }
            
            if(count==0){
                // (level &1) is important, can not omit ()
                if((level & 1) == 0){
                    reverse(temp.begin(),temp.end());
                }
                level++;
                count=qq.size();
                
                res.push_back(temp);
                temp.clear();
            }
        }
        
        return res;
        
    }
};