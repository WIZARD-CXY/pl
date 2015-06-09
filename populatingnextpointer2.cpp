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
            //travesal from up to down util meet NULL pointer
            
            TreeLinkNode *pre=NULL; //record the current level's pre-node
            TreeLinkNode *next=NULL; // record the next level's first node
            
            while(root){// travesal from left to right  until met NULL pointer
                if(next==NULL){
                    next=(root->left)?root->left:root->right;
                }
    
                if(root->left){
                    if(pre){
                        pre->next=root->left;
                    }
                    pre=root->left;
                }
                
                if(root->right){
                    if(pre){
                        pre->next=root->right;
                    }
                    pre=root->right;
                }
                root=root->next;
            }
            root=next;
        }
    }
};