class Solution {
public:
    /**
      * @param n: n
      * @param k: the kth permutation
      * @return: return the k-th permutation
      */
      
    int fact(int n){
        int res=1;
        
        for(int i=2;i<=n;i++){
            res*=i;
        }
        return res;
    }
    string getPermutation(int n, int k) {
        string pool(n,'0');
        string res="";
        
        for(int i=0; i<n; i++){
            pool[i]=i+1+'0';
        }
        int base=fact(n-1);
        k--;
        
        // set n element in res
        for(int i=n-1; i>0; i--){
            int idx=k/base;
            res+=pool[idx];
            //remove idx-th element out of pool
            pool.erase(pool.begin()+idx);
            // change base to next base and k
            k%=base;
            base/=i;
        }
        
        res+=pool[0];
        
        return res;
    }
       
};
