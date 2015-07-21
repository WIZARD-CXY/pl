class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "?" and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        // write your code here
        int sp=0;//record the current matching pos
        int pp=0;//record the p current maching pos
        int slen=strlen(s);
        int plen=strlen(p);
        //record p's star pos, initially we don't know if it exists
        //so set to the end
        int pstar=plen;
        int smatch=0;
        
        while(sp<slen){
            if(s[sp]==p[pp] || p[pp]=='?'){
                //exact match or match with "?"
                sp++;
                pp++;
                continue;
            }else if(p[pp]=='*'){
                // try to match * with zero char like `ab and a*b`
                pstar=pp;
                pp++;
                smatch=sp;
                continue;
            }
            
            if(pstar<plen){
                //try to match with 1 or more chars
                // like abcd a*d
                sp=++smatch;
                pp=pstar+1;
                continue;
            }
            return false;
        }
        
        while(pp <plen && p[pp]=='*'){
            pp++;
        }
        return pp==plen;
        
    }
};
