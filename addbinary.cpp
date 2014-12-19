class Solution {
public:
    string addBinary(string a, string b) {
        int carry=0;
        
        string res;
        
        int p=a.size()-1;
        int q=b.size()-1;
        int sum=0;
        
        while( p>=0 || q >=0 ){
            if(p>=0 && q>=0){
                sum=a[p--]-'0'+b[q--]-'0'+carry;
                res=(char)(sum%2+'0')+res;
                carry = sum/2;
            }else if(p >=0){
                sum=a[p--]-'0'+carry;
                res=(char)(sum%2+'0')+res;
                carry = sum/2;
            }else{
                sum=b[q--]-'0'+carry;
                res=(char)(sum%2+'0')+res;
                carry = sum/2;
                
            }
        }
        if(carry>0){
            res=(char)(carry+'0')+res;
        }
        return res;
        
    }
};