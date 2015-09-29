class Solution {
public:
    int hIndex(vector<int>& citations) {
        // like counting sort
        int n=citations.size();
        vector<int> cnt(n+1,0);
        
        for(auto c: citations){
            if(c>=n){
                cnt[n]++;
            }else{
                cnt[c]++;
            }
        }
        // cnt[i] records >= citation i's paper's number
        
        for(int i=n; i>=0; i--){
            if(cnt[i]>=i){
                return i;
            }
            
            if(i!=0){
                cnt[i-1]+=cnt[i];
            }
        }
        
        return 0;
    }
};