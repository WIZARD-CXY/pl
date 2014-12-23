class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n==0){
            return 0;
        }
        int last=A[0];
        int count=1;
        
        for(int i=1; i<n; i++){
            if(A[i]!=last){
                A[count++]=A[i];
                last=A[i];
            }
        }
        return count;
        
    }
};