class Solution {
public:
    bool isdigit(char c){
        return (c>='0' && c<='9');
    }
    int atoi(const char *str) {
        
        int len=strlen(str);
        if(len==0){
            return 0;
        }
        bool isNegative = false;
        int i=0;
        while(str[i]==' ' && i<len){
            i++;
        }
        if(str[i]=='-' || str[i] =='+'){
            if(str[i]=='-'){
                isNegative=true;
            }
            
            i++;
        }
        
        int end=i;
        
        while(isdigit(str[end])){
            end++;
        }
        string s = (string)str;
        s=s.substr(i,end-i);
        
        long long ret=0;
        stringstream ss;
        ss<<s;
        ss>>ret;
        if(isNegative){
            ret=-ret;
        }
        
        if(ret>INT_MAX){
            return INT_MAX;
        }else if(ret <INT_MIN){
            return INT_MIN;
            
        }else{
            return (int)ret;
        }
        return 0;
        
    }
};