class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n==0){
            return 0;
        }
        
        int f[n+1];
        f[0]=1;
        
        if(s[0]=='0'){
            f[1]=0;
        }else{
            f[1]=1;
        }
        
        for(int i=2; i<=n; i++){
            if(s[i-1]=='0'){
                // if s[i-1] is '0' can't form with the previous answer
                f[i]=0;
            }else{
                // else first join the previous answer
                f[i]=f[i-1];
            }
            // if the current one and previous one can join to 10<=num<=26, then f[i] can be joined with f[i-2]
            if(s[i-2]=='1' || (s[i-2]=='2' && s[i-1]<='6')){
                f[i]+=f[i-2];
            }
        }
        
        return f[n];
    }
};