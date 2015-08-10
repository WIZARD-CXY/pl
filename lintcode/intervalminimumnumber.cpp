/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
 struct SegmentMinTreeNode{
     int start,end,min;
     SegmentMinTreeNode *left,*right;
     SegmentMinTreeNode(int s, int e, int v){
         start=s;
         end=e;
         min=v;
         left=right=NULL;
     }
 };
class Solution { 
public:
    /**
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */
    vector<int> intervalMinNumber(vector<int> &A, vector<Interval> &queries) {
        // write your code here
        
        SegmentMinTreeNode *root=build(A,0,A.size()-1);
        
        vector<int> res;
        for(auto q : queries){
           res.push_back(query(root,q.start,q.end)); 
        }
        
        return res;
    }
    
    SegmentMinTreeNode* build(vector<int> &A,int start,int end){
        if(start>end){
            return NULL;
        }
        SegmentMinTreeNode *root=new SegmentMinTreeNode(start,end,INT_MAX);
        
        if(start==end){
            root->min=A[start];
            return root;
        }
        
        int mid=start+((end-start)>>1);
        
        root->left=build(A,start,mid);
        root->right=build(A,mid+1,end);
        
        int leftmin=root->left==NULL?INT_MAX:root->left->min;
        int rightmin=root->right==NULL?INT_MAX:root->right->min;
        
        root->min=min(leftmin,rightmin);
        
        return root;
    }
    
    int query(SegmentMinTreeNode *root, int start, int end){
        if(root==NULL || start> root->end || end< root->start){
            return INT_MAX;
        }
        
        if(root->start>=start && root->end<=end){
            return root->min;
        }
        
        int leftmin=query(root->left,start,end);
        int rightmin=query(root->right,start,end);
        
        return min(leftmin,rightmin);
            
    }
};
