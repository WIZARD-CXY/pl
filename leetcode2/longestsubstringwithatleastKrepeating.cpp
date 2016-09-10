class Solution {
public:
    int longestSubstring(string s, int k) {
        int i=0,res=0, n=s.size();
        
        while(i+k<=n){
            int mask=0;
            int mm[26]={0};
            int max_idx=i;
            
            for(int j=i; j<n; j++){
                int t=s[j]-'a';
                
                mm[t]++;
                if(mm[t]<k){
                    mask |= (1<<t);
                }else{
                    mask &= (~(1<<t));
                }
                
                if(mask==0){
                    res=max(res,j-i+1);
                    max_idx=j;
                }
            }
            i=max_idx+1;
        }
        
        return res;
    }
};