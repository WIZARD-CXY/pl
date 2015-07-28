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
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    TreeNode* buildTreefromInorder(vector<TreeNode*> &v, int start, int end){
        if(start>end){
            return NULL;
        }
        
        int mid=start+((end-start)>>1);
        
        v[mid]->left=buildTreefromInorder(v,start,mid-1);
        v[mid]->right=buildTreefromInorder(v,mid+1,end);
        
        return v[mid];
    }
    TreeNode* removeNode(TreeNode* root, int value) {
        // write your code here
        // first use iterative inorder travesal to store result into a vector
        vector<TreeNode*> v;
        stack<TreeNode*> ss;
        TreeNode *cur=root,*tmp;
        
        while(cur!=NULL || !ss.empty()){
            if(cur!=NULL){
                //visit its left child
                ss.push(cur);
                cur=cur->left;
            }else{
                tmp=ss.top();
                ss.pop();
                cur=tmp->right;
                if(tmp->val!=value){
                    v.push_back(tmp);
                }else{
                    delete tmp;
                    tmp=NULL;
                }
            }
        }
        
        return buildTreefromInorder(v,0,v.size()-1);
    }
};
