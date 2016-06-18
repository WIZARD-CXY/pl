class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.size()==0) return s.size()==0;
        
        if(p[1] != '*'){
            //p[1]==0 or p[1]==alphabet or .
            if(p[0]==s[0] || (p[0]=='.' && s.size()>0)){
                return isMatch(s.substr(1),p.substr(1));
            }else{
                return false;
            }
        }else{
            //p[1]=='*'
            while(p[0]==s[0] || (p[0]=='.' && s.size()>0)){
                if(isMatch(s,p.substr(2))){
                    return true;
                }
                // move s one step forward match 0 or more char
                s=s.substr(1);
            }
            return isMatch(s,p.substr(2));
        }  
    }
};