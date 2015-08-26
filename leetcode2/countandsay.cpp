class Solution {
public:
    string countAndSay(int n) {
        string res="1";
        string preres;
        
        for(int i=2; i<=n; i++){
            int cnt=1;
            preres=res;
            res="";
            char last=preres[0];
            
            for(int j=1; j<preres.size();j++){
                if(last!=preres[j]){
                    res+=to_string(cnt)+last;
                    last=preres[j];
                    cnt=1;
                }else{
                    cnt++;
                }
            }
            res+=to_string(cnt)+last;
        }
        
        return res;
    }
};