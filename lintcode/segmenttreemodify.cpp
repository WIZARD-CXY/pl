/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param root, index, value: The root of segment tree and 
     *@ change the node's value with [index, index] to the new given value
     *@return: void
     */
    void modify(SegmentTreeNode *root, int index, int value) {
        // write your code here
        // base case 1 out of range
        if(root==NULL || index>root->end || index<root->start){
            return;
        }
        //base case 2
        //find the value
        if(root->start==index && root->end==index){
            root->max=value;
            return;
        }
        //recursive call the right and left subtree
        modify(root->left,index,value);
        modify(root->right,index,value);
        
        int left_max=root->left==NULL?INT_MIN:root->left->max;
        int right_max=root->right==NULL?INT_MIN:root->right->max;
        
        //update root->max
        root->max=max(left_max,right_max);
    }
};
