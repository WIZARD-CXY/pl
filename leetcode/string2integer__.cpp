class Solution {
public:
    int myAtoi(string str) {
        int n=str.size();
        int sign=1;
        
        int i=0;
        while(i<n && str[i]==' '){
            i++;
        }
        
        if(str[i]=='+' || str[i]=='-'){
            if(str[i]=='-'){
                sign=-1;
            }
            i++;
        }
        
        int sum=0;
        
        while(i<n && str[i]>='0' && str[i]<='9'){
            if(sum>INT_MAX/10 || (sum==INT_MAX/10)&&((str[i]-'0')>INT_MAX%10)){
                return sign==1?INT_MAX:INT_MIN;
                
            }
            sum=sum*10+str[i]-'0';
            i++;
            
        }
        return sum*sign;
        
    }
};