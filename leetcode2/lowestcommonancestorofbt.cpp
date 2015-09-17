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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;
        
        findpath(path1,root,p);
        findpath(path2,root,q);
        
        int i=0;
        int j=0;
        
        TreeNode* res;
        
        while(i<path1.size() && j<path2.size()){
            if(path1[i]!=path2[j]){
                return res;
            }else{
                res=path1[i];
            }
            i++;
            j++;
            
        }
        
        return res;
    }
    
    bool findpath(vector<TreeNode*> &path,TreeNode* root, TreeNode *p){
        if(root==NULL){
            return false;
        }
        path.push_back(root);
        if(root==p){
           //find the node
           return true;
        }
        
        //recursive find in left and right sub tree
        
        bool found=findpath(path,root->left,p) || findpath(path,root->right,p);
        
        if(!found){
            path.pop_back();
        }
        
        return found;
    }
    
};