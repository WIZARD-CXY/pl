class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
         //old way from merge sort
         int x=0;
         int y=0;
         int i=0;
         int T[m+n];
         
         while(x<m || y<n){
             if((y>=n) || (x<m && A[x] <= B[y])) {
                 T[i++] = A[x++];
             }else{
                 T[i++] = B[y++];
             }
             
         }
         
         for(int i=0; i<m+n; i++){
             A[i]=T[i];
         }
        
    }
};