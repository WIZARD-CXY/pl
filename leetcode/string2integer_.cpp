class Solution {
public:
    bool isdigit(char c){
        return (c>='0' && c<='9');
    }
    int atoi(const char *str) {
        
        bool isNegative = false;
        int i=0;
        while(str[i]==' '){
            i++;
        }
        
        if(str[i]=='\0'){
            return 0;
        }
        if(str[i]=='-' || str[i] =='+'){
            if(str[i]=='-'){
                isNegative=true;
            }
            
            i++;
        }
        
        int end=i;
        long long res=0;
        int sign=1;
        if(isNegative){
            sign=-1;
        }
        
        while(isdigit(str[end])){
            res=res*10+str[end]-'0';
            if(res*sign>INT_MAX){
               return INT_MAX;
            }
            if(res*sign <INT_MIN){
               return INT_MIN;
            }
            end++;
        }
        return sign*res;
    }
};