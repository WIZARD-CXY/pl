class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        
        int carry=0;
        
        int p=a.size()-1,q=b.size()-1;
        int sum=0;
        
        while(p>=0 || q>=0){
            if(p>=0 && q>=0){
                sum=a[p]-'0'+b[q]-'0'+carry;
                carry=sum/2;
                res=char(sum%2+'0')+res;
                p--;
                q--;
            }else if(p>=0){
                sum=a[p]-'0'+carry;
                carry=sum/2;
                res=char(sum%2+'0')+res;
                p--;
            }else if(q>=0){
                sum=b[q]-'0'+carry;
                carry=sum/2;
                res=char(sum%2+'0')+res; 
                q--;
            }
        }
        if(carry>0){
            res=char(carry+'0')+res;
        }
        return res;
        
    }
};