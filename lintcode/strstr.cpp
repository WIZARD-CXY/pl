class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        // write your code here
        if(source == NULL || target ==NULL){
            return -1;
        }
        
        int slen=strlen(source);
        int tlen=strlen(target);
        
        if(slen==0 && tlen==0){
            return 0;
        }
        int i=0;
        int j;
        
        while(i<=slen-tlen){
            int tempi=i;
            j=0;
            while(tempi<slen && j<tlen && source[tempi]==target[j]){
                tempi++;
                j++;
            }
            
            if(j==tlen){
                return i;
            }
            i=tempi+1;
        }
        
        
        return -1;
    }
};

