/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        
        while(root){
            TreeLinkNode *pre=NULL; // root next level pre node
            TreeLinkNode *nextlevelfirst=NULL; // next level first element
            
            while(root){
                if(nextlevelfirst==NULL){
                    nextlevelfirst=(root->left!=NULL)?root->left:root->right;//set the next level first
                }
                
                if(root->left){
                    if(pre!=NULL){
                        pre->next=root->left;
                    }
                    pre=root->left;
                }
                if(root->right){
                    if(pre!=NULL){
                        pre->next=root->right;
                    }
                    pre=root->right;
                }
                root=root->next;
            }
           
            //move down 
            root=nextlevelfirst;
        }
    }
};