#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
#include<limits.h>
#include<stack>
#include<queue>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
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
                if(level %2==0){
                    reverse(temp.begin(), temp.end());
                }
                level++;
                count=qq.size();
                
                res.push_back(temp);
                temp.clear();
            }
        }
        
        return res;
        
    }


int main(){
   TreeNode *root= new TreeNode(1);
   TreeNode *left= new TreeNode(2);
   TreeNode *right= new TreeNode(3);
   root->left=left;
   root->right=right;

   zigzagLevelOrder(root);
}