/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode *root) {

    	if(root==NULL){
    		return 0;
    	}
    	
    	queue<TreeNode*> q;
    	q.push(root);

    	int count = 1; //record every level's unvisited node number
    	int depth=0;

    	while(!q.empty()){
    		TreeNode *temp=q.top();
    		q.pop();
    		count--;

    		if(temp->left){
    			q.push(temp->left);
    		}
    		if(temp->right){
    			q.push(temp->right);
    		}

    		if(count==0){
    			depth++;
    			count=q.size();
    		}

    	}
        
};