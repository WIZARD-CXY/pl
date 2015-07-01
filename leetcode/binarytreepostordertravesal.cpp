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
        vector<int> res;
        
        //p is the current visiting pointer,q is just visited poointer
        
        TreeNode *p,*q;
        
        stack<TreeNode*> ss;
        
        p=root;
        
        do{
            while(p!=NULL){
                //go left;
                ss.push(p);
                p=p->left;
            }
            q=NULL;
            
            while(!ss.empty()){
                p=ss.top();
                ss.pop();
                
                if(p->right==q){
                    //right child is visited or no exist
                    //add to res
                    res.push_back(p->val);
                    q=p;
                }else{
                    //not ready yet.push it back
                    ss.push(p);
                    p=p->right;
                    break;
                }
                 
            }
            
        }while(!ss.empty());
        return res;
        
    }
};