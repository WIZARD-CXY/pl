//referennce http://blog.csdn.net/feliciafay/article/details/18999903
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        
        bool res[s.size()+1]; 
        memset(res, 0, sizeof(res));
        
        res[0]=1;
        
        for(int i=1; i<=s.size(); i++){
            for(int j=i-1; j>=0; j--){
                if(res[j] && dict.find(s.substr(j,i-j))!=dict.end()){
                    res[i]=1;
                    break;
                }
                
            }
        }
        return res[s.size()];
        
    }
};