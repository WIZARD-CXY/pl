class Solution {
public:
    int strStr(char *haystack, char *needle) {
        int hsize = strlen(haystack);
        int nsize = strlen(needle);
        
        for(int i=0; i<=(hsize-nsize); i++){
            int j;
            for(j=0; j<nsize; j++){
                if(haystack[j+i] != needle[j]){
                    break;
                }
            }
            if(j==nsize){
                return i;
            }
        }
        
        return -1;
    }
};