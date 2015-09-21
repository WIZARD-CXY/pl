class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int slen=s.size();
        int tlen=t.size();
        
        // always have s smaller than t
        if(slen>tlen){
            return isOneEditDistance(t,s);
        }
        
        if(tlen-slen>1){
            return false;
        }
        
        bool mismatch=false;
        for(int i=0; i<slen; i++){
            if(s[i]!=t[i]){
                if(slen==tlen){
                    //only replace
                    s[i]=t[i];
                }else{
                    // insert t[i] to s
                    s.insert(i,1,t[i]);
                }
                mismatch=true;
                break;
            }
        }
               //ab abc need add to last word
        return (!mismatch && tlen-slen==1) || (mismatch && t==s);
    }
};