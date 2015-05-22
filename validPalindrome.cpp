class Solution {
public:
    bool isAlphaOrNum(char c){
        if( (c >= 'a' && c <= 'z')  || (c >= '0' && c <= '9') || ( c >= 'A' && c <='Z' ) ){
            return true;
        }else{
            return false;
        }
    }
    
    bool isPalindrome(string s) {
        if(s == ""){
            return true;
        }
        
        int q=s.size()-1;
        int p=0;
        bool flag=true;
        
        while(p<q){
            
            if(!isAlphaOrNum(s[p])){
                p++;
                continue;
            }
            if(!isAlphaOrNum(s[q])){
                q--;
                continue;
            }
            //convert to lower case
            if(s[q]>='A' && s[q] <='Z'){
                s[q]=s[q]-'A'+'a';
            }
            //convert to lower case
            if(s[p]>='A' && s[p] <='Z'){
                s[p]=s[p]-'A'+'a';
            }
            
            if(s[p]!=s[q]){
                flag=false;
                break;
            }
            p++;
            q--;
        }
        return flag;
    }
};
