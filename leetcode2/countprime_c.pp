class Solution {
public:
    int countPrimes(int n) {
        vector<bool> vis(n,0);
        int cnt=0;
        for(int i=2; i<n; i++){
            if(!vis[i]){
                cnt++;
                for(int j=i; j<n; j+=i){
                   vis[j]=1;
                }
            }
            
        }
        
        return cnt;
    }
};