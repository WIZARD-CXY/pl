class Solution {
public:
    int countPrimes(int n) {
        vector<bool> vis(n,0);
        
        for(int i=2; i<sqrt(n); i++){
            if(!vis[i]){
                // j*i may overflow when n is large near INT_MAX
                for(int j=i; j*i<n; j++){
                   vis[j*i]=1;
                }
            }
            
        }
        
        int cnt=0;
        for(int i=2; i<n; i++){
            if(!vis[i]){
                cnt++;
            }
        }
        
        return cnt;
    }
};