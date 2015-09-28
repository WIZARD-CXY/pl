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
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode *root) {
        // write your code here
        ostringstream sout;
        _se(root,sout);
        
        return sout.str();
    }
    
    void _se(TreeNode *root, ostringstream &sout){
        if(root==NULL){
            sout<<"# ";
            return;
        }
        sout<<root->val<<" ";
        _se(root->left,sout);
        _se(root->right,sout);
        
    }
    
    TreeNode* _de(istringstream &sin){
        char token[20];
        sin>>token;
        if(token[0]=='#'){
            return NULL;
        }
        
        TreeNode *root= new TreeNode(atoi(token));
        root->left=_de(sin);
        root->right=_de(sin);
        
        return root;
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TreeNode *deserialize(string data) {
        // write your code here
        istringstream sin(data);
        return _de(sin);
        
    }
};

