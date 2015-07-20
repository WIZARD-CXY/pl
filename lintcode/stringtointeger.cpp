class Solution {
public:
    /**
     * @param str: A string
     * @return An integer
     */
    int atoi(string str) {
        // write your code here
        
        int len=str.size();
        
        if(len==0){
            return 0;
        }
        
        int sign=1;
        int i=0;
        //delete leading space
        while(i<len && str[i]==' '){
            i++;
        }
        
        if(str[i]=='+'||str[i]=='-'){
            if(str[i]=='-'){
               sign=-1; 
            }
            i++;
        }
       
        long long sum=0;
        while(i<len && str[i]>= '0' && str[i]<='9'){
            sum=sum*10+str[i]-'0';
            if(sign*sum>INT_MAX){
                return INT_MAX;
            }else if(sign*sum<INT_MIN){
                return INT_MIN;
            }
            i++;
        }
     
        
        return sign*sum;
    }
};
