class Solution {
public:
    /**
     * @param A: sorted integer array A which has m elements, 
     *           but size of A is m+n
     * @param B: sorted integer array B which has n elements
     * @return: void
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        // write your code here
        //merge from the tail to head of A
        int p=m-1;
        int q=n-1;
        int x=m+n-1;
        
        while(p>=0 || q >=0){
            if(q<0 || (p>=0 && A[p]>=B[q])){
                A[x--]=A[p--];
            }else{
                A[x--]=B[q--];
            }
        }
    }
};
