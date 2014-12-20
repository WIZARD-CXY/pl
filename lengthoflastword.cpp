class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int p=strlen(s);
        int q=0;
        
        if(p==0){
            return 0;
        }
        int end=p-1;
        
        while(end>=0 && s[end]==' '){
            end--;
        }
        if(end==-1){
            return 0;
        }
        
        int begin=end;
        
        while(begin>=0 && s[begin] !=' '){
            begin--;
        }
        
        return end-begin;
        
    }
};