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
    vector<int> ivec;
    int index=0;
    BSTIterator(TreeNode *root) {
        inOrder(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return index<ivec.size();
    }

    /** @return the next smallest number */
    int next() {
        return ivec[index++];
        
    }
    void inOrder(TreeNode *root){
        if(root){
            inOrder(root->left);
            ivec.push_back(root->val);
            inOrder(root->right);
        }
        
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */