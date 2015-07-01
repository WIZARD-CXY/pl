class Solution {
public:
    int singleNumber(int A[], int n) {
        int count[32]={0};
        int res=0;
        
        for(int i=0; i<32; i++){
            for(int j=0; j<n; j++){
                if((A[j]>>i)&1){
                    count[i]++;
                }
            }
            
            res|= ((count[i]%3)<<i);
        }
        return res;
    }
};