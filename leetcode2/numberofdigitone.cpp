class Solution {
public:
    int countDigitOne(int n) {
        int k=1;
        int res=0;
        long long base=1; //in case base*10 overflow
        
        while(n/base){
            int cur=(n/base)%10;
            int low=n%base;
            int high=n/base/10;
            
            if(cur>k){
                res+=(high+1)*base;
            }else if(cur==k){
                res+=high*base+low+1;
            }else{
                res+=high*base;
            }
            base*=10;
        }
        
        return res;
    }
};