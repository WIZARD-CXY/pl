class Solution {
public:
    int min=0x7ffffff;
    int minDepth(TreeNode *root) {
        if(root==NULL){
            return 0;
        }
        dfs(root,0);
        
        return min;
    }
    
    void dfs(TreeNode *node, int curDepth){
        curDepth++;
        
        if(node->left == NULL && node->right ==NULL){
            if(curDepth<min){
                min=curDepth;
            }
            return;
        }
        
        if(node->left){
            dfs(node->left,curDepth);
        }
        
        if(node->right){
            dfs(node->right,curDepth);
        }
    }
};