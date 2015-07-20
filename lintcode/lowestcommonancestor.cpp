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
public:
    /**
     * @param root: The root of the binary search tree.
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    bool dfs(TreeNode *root, TreeNode *target, vector<TreeNode*> &path){
        if(root==NULL){
            return false;
        }
        path.push_back(root);
        if(root==target){
            return true;
        }
        
        bool found=dfs(root->left,target,path)||dfs(root->right,target,path);
        
        if(!found){
            path.pop_back();
        }
        
        return found;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
        // write your code here
        if(root==NULL){
            return NULL;
        }
        
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;
        
        //find the root to A path1
        dfs(root,A,path1);
        //find the root to B path2
        dfs(root,B,path2);
        
        TreeNode *res;
        vector<TreeNode*>::iterator it1=path1.begin();
        vector<TreeNode*>::iterator it2=path2.begin();
        while(it1!=path1.end() && it2!=path2.end()){
            if(*it1==*it2){
                res=*it1;
            }
            it1++;
            it2++;
        }
        
        return res;
    }
};
