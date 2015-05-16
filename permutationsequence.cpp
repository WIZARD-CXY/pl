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
        string s(n,'0');
        string result="";
        
        for(int i=0; i<n; i++){
            s[i]+=i+1;
        }
        
        k--;
        
        int base=fact(n-1);
        
        for(int i=n-1; i>0;i--){
            int idx = k/base;
            char ch = s[idx];
            result.push_back(ch);
            s.erase(s.begin()+idx);
            k%=base;
            base/=i;
        }
        result.push_back(s[0]);
        
        return result;
    }
};