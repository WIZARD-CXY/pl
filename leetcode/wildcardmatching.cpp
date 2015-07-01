class Solution {
public:
    bool isMatch(string s, string p) {
        int ssize=s.size();
        int psize=p.size();
        
        int i=0;//record current s pos
        int j=0;//record current patten pos
        
        int pi=0,pj=psize;//pj record the star pos of p, set it to the end
        
        while(i<ssize){
            if(s[i]==p[j] || p[j]=='?'){
                //current match
                i++;
                j++;
                continue;
            }
            
            if(p[j]=='*'){
                //match zero char
                pj=j++;
                pi=i;
                continue;
            }
            
            if(pj<psize){
                j=pj+1;//match 1,2,3,4 or more chars
                i=++pi;
                continue;
            }
            return false;
        }
        
        while(p[j]=='*'){
            j++;// skip trailing star
        }
        
        return j==psize; // if all trailing star return true
        
    }
};