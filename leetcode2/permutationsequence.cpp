class Solution {
public:
    int fact(int n){
        int res=1;
        
        for(int i=2; i<=n; i++){
            res*=i;
        }
        
        return res;
    }
    string getPermutation(int n, int k) {
        string res="";
        string pool(n,'0');
        
        //make a pool of digit
        for(int i=0; i<n; i++){
            pool[i]=i+1+'0';
        }
        int base=fact(n-1);
        k--;//convert to 0 index based
        
        for(int i=n-1; i>=0; i--){
            int idx=k/base;
            res+=pool[idx];
            
            //remove from pool
            pool.erase(pool.begin()+idx);
            
            // change to next iteration
            k%=base;
            base/=i;
        }
        res+=pool[0];
        
        return res;
    }
};