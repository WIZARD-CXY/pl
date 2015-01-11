class Solution {
public:
    int maxProduct(int A[], int n) {
        if(n==0){
            return 0;
        }
        int maxtemp = A[0];
        int mintemp = A[0];
        int res= A[0];
        
        for(int i=1; i<n; i++){
            int tempmax=A[i]*maxtemp;
            int tempmin=mintemp=A[i]*mintemp;
            
            maxtemp=max(A[i],max(tempmax,tempmin));
            mintemp=min(A[i],min(tempmax,tempmin));
            
            
            
            res=max(maxtemp,res);
        }
        return res;
    }
};