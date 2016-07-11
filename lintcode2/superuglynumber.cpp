class Solution {
public:
    /**
     * @param n a positive integer
     * @param primes the given prime list
     * @return the nth super ugly number
     */
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        // Write your code here
        int len=primes.size();
        
        vector<int> ugly(n,INT_MAX);
        vector<int> idx(len,0);
        
        ugly[0]=1;
        for(int i=1; i<n; i++){
            for(int j=0; j<len; j++){
                ugly[i]=min(ugly[i],primes[j]*ugly[idx[j]]);
            }
            
            
            for(int j=0; j<len; j++){
                if(ugly[i]==primes[j]*ugly[idx[j]]){
                    idx[j]++;
                }
            }
            
        }
        
        return ugly[n-1];
    }
};