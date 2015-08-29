class Solution {
public:
    string addBinary(string a, string b) {
        int asize=a.size();
        int bsize=b.size();
        string res;
        
        int carry=0;
        
        int i=asize-1,j=bsize-1;
        
        while(i>=0 || j>=0){
            int sum;
            
            if(i>=0 && j>=0){
                sum=a[i]-'0'+b[j]-'0'+carry;
            }else if(i>=0){
                sum=a[i]-'0'+carry;
            }else if(j>=0){
                sum=b[j]-'0'+carry;
            }
            res=char(sum%2+'0')+res;
            carry=sum/2;
            i--;
            j--;
        }
        if(carry){
            res=char(carry+'0')+res;
        }
        
        return res;
        
    }
};