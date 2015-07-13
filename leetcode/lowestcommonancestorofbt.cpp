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
    bool dfs(TreeNode *root, TreeNode *target, vector<TreeNode*> &path){
        if(root!=NULL){
            bool found =false;
            
            path.push_back(root);
            
            if(root==target){
                return true;
            }
        
            //if found one, prune
            found=dfs(root->left,target,path)||dfs(root->right,target,path);
           
            if(!found){
                 path.pop_back();
            } 
           
            return found;
        }
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || p ==NULL || q==NULL){
            return NULL;
        }
        
        // path1 record the root to p's path
        vector<TreeNode*> path1;
        dfs(root,p,path1);
        
        //path2 record the roor to q's path
        vector<TreeNode*> path2;
        dfs(root,q,path2);
        
        vector<TreeNode*>::iterator iter1 = path1.begin();
        vector<TreeNode*>::iterator iter2 = path2.begin();
        
        TreeNode* LastSame=NULL;
        while(iter1 != path1.end() && iter2 != path2.end()){
            if(*iter1==*iter2){
                LastSame=*iter1;
            }
            iter1++;
            iter2++;
        }
        
        return LastSame;
    }
};