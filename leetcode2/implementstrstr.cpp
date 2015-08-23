class Solution {
public:
    int strStr(string haystack, string needle) {
        int hlen=haystack.size();
        int nlen=needle.size();
        
        for(int i=0; i<=hlen-nlen; i++){
            int j;
            for(j=0; j<nlen; j++){
                if(haystack[i+j]!=needle[j]){
                    break;
                }
            }
            
            if(j==nlen){
                return i;
            }
        }
        
        return -1;
    }
};