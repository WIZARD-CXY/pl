class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
         int x=m-1;
         int y=n-1;
         int i=m+n-1;
         
         while(x>=0 || y>=0){
             if((y<0) || (x>=0 && A[x] >= B[y])) {
                 A[i--] = A[x--];
             }else{
                 A[i--] = B[y--];
             }
             
         }
        
    }
};