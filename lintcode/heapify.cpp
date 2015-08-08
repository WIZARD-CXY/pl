class Solution {
public:
    /**
     * @param A: Given an integer array
     * @return: void
     */
    void heapify(vector<int> &A) {
        // write your code here
        int n=A.size();
        
        for(int i=(n-1)/2; i>=0; i--){
            minheapify(A,i,n);
        }
    }
    
    void minheapify(vector<int> &A, int i,int heapsize){
        int l=2*i+1;
        int r=2*i+2;
        
        
        int smallest=i;
        
        if(l<heapsize && A[l]<A[smallest]){
            smallest=l;
        }
        
        if(r<heapsize && A[r]<A[smallest]){
            smallest=r;
        }
        
        if(i!=smallest){
            swap(A[i],A[smallest]);
            minheapify(A,smallest,heapsize);
        }
    }
};
