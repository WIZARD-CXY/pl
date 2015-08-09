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
     *@param root, start, end: The root of segment tree and 
     *                         an segment / interval
     *@return: The maximum number in the interval [start, end]
     */
    int query(SegmentTreeNode *root, int start, int end) {
        // write your code here
        if(root==NULL || root->start>end || root->end<start){
            return INT_MIN;
        }
        
        // query range [start,end] include the root node range
        // just return
        if(root->start>=start && root->end<=end){
            return root->max;
        }
        
        int l=query(root->left,start,end);
        int r=query(root->right,start,end);
        
        return max(l,r);
    }
};
