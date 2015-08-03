class Solution {
public:
    /**
     * @param key: A String you should hash
     * @param HASH_SIZE: An integer
     * @return an integer
     */
    int hashCode(string key,int HASH_SIZE) {
        // write your code here
        int res=0;
        
        int n=key.size();
        int base=1;
        for(int i=n-1; i>=0; i--){
            // notice key[i]*base may overflow for a int
            int tmp=(long long)key[i]*base%HASH_SIZE;
            // notice mulpiply may overflow
            base=(long long)base*33%HASH_SIZE;
            
            res=(res+tmp)%HASH_SIZE;
        }
        
        return res;
    }
};
