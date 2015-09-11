/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        pushroot(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !ss.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *tmp=ss.top();
        ss.pop();
        
        pushroot(tmp->right);
        return tmp->val;
    }
    stack<TreeNode*> ss;
    void pushroot(TreeNode *root){
        while(root){
            ss.push(root);
            root=root->left;
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */