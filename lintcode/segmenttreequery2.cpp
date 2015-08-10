/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, count;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int count) {
 *         this->start = start;
 *         this->end = end;
 *         this->count = count;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param root, start, end: The root of segment tree and 
     *                         an segment / interval
     *@return: The count number in the interval [start, end] 
     */
    int query(SegmentTreeNode *root, int start, int end) {
        // write your code here
        if(root==NULL || root->start>end || root->end<start){
            return 0;
        }
        // root range is in query range
        if(root->start>=start && root->end<=end){
            return root->count;
        }
        
        int left_count=query(root->left,start,end);
        int right_count=query(root->right,start,end);
        
        return left_count+right_count;
    }
};
