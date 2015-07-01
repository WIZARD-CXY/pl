class Solution {
public:
    int countPrimes(int n) {
        bool res[n];
        
        memset(res,0,sizeof(res));
        
        for(int i=2; i*i<n; i++){
            if(res[i]==false){
                for(int j=i; i*j<n; j++){
                    res[i*j]=1;
                }
            }
        }
        
        int count=0;
        for(int i=2; i<n; i++){
            if(res[i]==false){
                count++;
            }
        }
        return count;
    }
};