class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int plen=pattern.size();
        
        unordered_map<char,string> mm1;
        unordered_map<string,char> mm2;
        
        int p=0,q=0;
        int idx=0;
        
        while(q<str.size()){
            while(q<str.size() && str[q]!=' '){
                q++;
            }
            
            string tmp=str.substr(p,q-p);
          
            p=q=q+1;
            
            if(mm1.find(pattern[idx])==mm1.end()){
                mm1[pattern[idx]]=tmp;
            }else{
                if(mm1[pattern[idx]]!=tmp){
                    return false;
                }
            }
            
             if(mm2.find(tmp)==mm2.end()){
                mm2[tmp]=pattern[idx];
            }else{
                if(mm2[tmp]!=pattern[idx]){
                    return false;
                }
            }
            idx++;
        }
        //pattern size is not same with the str number
        if(idx!=plen){
            return false;
        }
        
        return true;
    }
};