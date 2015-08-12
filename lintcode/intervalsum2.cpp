struct SegmentSumNode{
    int start,end;
    long long sum;
    SegmentSumNode *left,*right;
    SegmentSumNode(int s, int e, long long v){
        start=s;
        end=e;
        sum=v;
        left=right=NULL;
    }
};

class Solution {
public:
    /* you may need to use some attributes here */
    

    /**
     * @param A: An integer vector
     */
    Solution(vector<int> A) {
        // write your code here
        root=build(A,0,A.size()-1);
    }
    
    /**
     * @param start, end: Indices
     * @return: The sum from start to end
     */
    long long query(int start, int end) {
        // write your code here
        return helper(root,start,end);
    }
    
    long long helper(SegmentSumNode *root, int start, int end){
        if(root==NULL || root->start>end || root->end<start){
            return 0;
        }
        
        if(root->start>=start && root->end<=end){
            return root->sum;
        }
        
        long long lsum=helper(root->left,start,end);
        long long rsum=helper(root->right,start,end);
        
        return lsum+rsum;
    }
    
    /**
     * @param index, value: modify A[index] to value.
     */
    void modify(int index, int value) {
        // write your code here
         helper2(root,index,value);
    }
    
    void helper2(SegmentSumNode *root, int index ,int val){
        if( root==NULL || root->start>index || root->end<index){
            return;
        }
        
        if(root->start==root->end && root->start==index){
            root->sum=val;
            return;
        }
        
        helper2(root->left,index,val);
        helper2(root->right,index,val);
        
        long long lsum=root->left?root->left->sum:0;
        long long rsum=root->right?root->right->sum:0;
        
        root->sum=lsum+rsum;
    }
    
    SegmentSumNode* build(vector<int> &A, int start, int end){
        if(start>end){
            return NULL;
        }
        
        SegmentSumNode *root= new SegmentSumNode(start,end,0);
        
        if(start==end){
            root->sum=A[start];
            return root;
        }
        
        int mid=start+((end-start)>>1);
        root->left=build(A,start,mid);
        root->right=build(A,mid+1,end);
        
        long long lsum=root->left?root->left->sum:0;
        long long rsum=root->right?root->right->sum:0;
        
        root->sum=lsum+rsum;
        
        return root;
    }
private:
    SegmentSumNode *root;
};