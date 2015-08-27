class Solution {
public:
    bool isMatch(string s, string p) {
        int slen=s.size();
        int plen=p.size();
        
        int pp=0;
        int sp=0;
        int pstar=plen;
        int smatchpos=0; //record s math pos
        
        while(sp<slen){
            if(pp<plen && s[sp]==p[pp] || p[pp]=='?'){
                //exact match one word 
                sp++;
                pp++;
                continue;
            }
            if(pp<plen && p[pp]=='*'){
                //try to match 0 char like ab a*b
                pstar=pp;
                //only move p forward
                pp++;
                smatchpos=sp;
                continue;
            }
            
            if(pstar<plen){
                // match more word abcd to ab*d
                sp=++smatchpos;
                pp=pstar+1;
                continue;
            }
            
            return false;
        }
        
        while(pp<plen && p[pp]=='*'){
            pp++;
        }
        
        return pp==plen;
        
    }
};