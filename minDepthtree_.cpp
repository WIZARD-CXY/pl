#include <iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int minD=0x7ffffff;
void dfs(TreeNode *node, int curDepth){
    curDepth++;
    
    if(node->left == NULL && node->right == NULL){
        if(curDepth<minD){
            minD=curDepth;
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
int minDepth(TreeNode *root) {
    if(root==NULL){
        return 0;
    }
    
    int leftDepth=minDepth(root->left);
    int rightDepth=minDepth(root->right);

    return min(leftDepth,rightDepth)+1;
    
}



int main(){
    TreeNode *root= new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=NULL;
    cout<<minDepth(root)<<endl;

}