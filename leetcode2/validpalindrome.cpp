class Solution {
public:
    bool isvalid(char c){
        if(isdigit(c) || isalpha(c)){
            return true;
        }else{
            return false;
        }
    }
    bool isPalindrome(string s) {
        int n=s.size();
        
        if(n==0){
            return true;
        }
        
        int start=0;
        int end=n-1;
        
        while(start<end){
            if(!isvalid(s[start])){
                start++;
                continue;
            }
            
            if(!isvalid(s[end])){
                end--;
                continue;
            }
            
            //convert to lower case
            if(s[start]>='A' && s[start]<='Z'){
                s[start]=s[start]-'A'+'a';
            }
            //convert to lower case
            if(s[end]>='A' && s[end]<='Z'){
                s[end]=s[end]-'A'+'a';
            }
            
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        
        return true;
    }
};