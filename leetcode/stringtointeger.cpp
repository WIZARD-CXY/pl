class Solution {
public:
    int myAtoi(string str) {
        int len=str.size();
        
        // remove leading space
        int i=0;
        while(i<len && str[i]==' '){
            i++;
        }
        
        //remove trailing space
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
        for(;i<=j; i++){
            if(str[i]>='0' && str[i]<='9'){
                res=res*10+str[i]-'0';
            }else{
                // not digit just break
                break;
            }
            
            if(sign*res>=INT_MAX){
                return INT_MAX;
            }else if(sign*res<=INT_MIN){
                return INT_MIN;
            }
        }
        
        return sign*res;
    }
};