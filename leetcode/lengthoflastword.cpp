class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=s.size();
        int p=len-1;
        
        // remove trailing ' '
        while(p>=0 && s[p]==' '){
            p--;
        }
        
        if(p==-1){
            return 0;
        }
        
        int end=p;
        
        while(p>=0 && s[p]!=' '){
            p--;
        }

        return end-p;
        
    }
};