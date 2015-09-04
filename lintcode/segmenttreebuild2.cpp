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
     *@param A: a list of integer
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(vector<int>& A) {
        // write your code here
        return build(A,0,A.size()-1);
    }
    
    SegmentTreeNode* build(vector<int> &A, int start,int end){
        if(start>end){
            return NULL;
        }
        
        if(start==end){
            SegmentTreeNode *root=new SegmentTreeNode(start,end,A[start]);
            return root;
        }
        
        SegmentTreeNode *root=new SegmentTreeNode(start,end,0);
        int mid=start+((end-start)>>1);
        root->left=build(A,start,mid);
        root->right=build(A,mid+1,end);
        
        root->max=max(root->left->max,root->right->max);
        
        return root;
    }
};
