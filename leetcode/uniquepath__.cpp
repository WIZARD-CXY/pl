class Solution {
public:
    int uniquePaths(int m, int n) {
        return com(m+n-2,max(m-1,n-1));
        
    }
    long long fact(int n, int start=1){
        long long res=1;
        
        for(int i=start;i<=n;i++){
            res*=i;
        }
        return res;
    }
    long long com(int n, int k){
        // used for calculate Cnk
        if (k==0){
            return 1;
        }
        
        if(k==1){
            return n;
        }
        
        long long ret=fact(n,k+1);
        ret/=fact(n-k);
        return ret;
    }
};