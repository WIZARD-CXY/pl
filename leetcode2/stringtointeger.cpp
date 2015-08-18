class Solution {
public:
    int myAtoi(string str) {
        int len=str.size();
        
        int i=0;
        //remove leading ' '
        while(i<len && str[i]==' '){
            i++;
        }
        
        //remove trailing ' '
        int j=len-1;
        while(j>=0 && str[j]==' '){
            j--;
        }
        
        if(i>j){
            return 0;
        }
        
        int sign=1;
        if(str[i]=='+' || str[i]=='-'){
            if(str[i]=='-'){
                sign=-1;
            }
            i++;
        }
        
        long long res=0;
        
        while(i<=j){
            if(!isdigit(str[i])){
                return sign*res;
            }
            res=res*10+str[i]-'0';
            i++;
            if(sign*res > INT_MAX ){
                return INT_MAX;
            }else if(sign*res <INT_MIN){
                return INT_MIN;
            }
        }
        
        return sign*res;
        
    }
};