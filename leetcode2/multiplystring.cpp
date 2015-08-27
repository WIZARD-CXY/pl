class Solution {
public:
    string multiply(string num1, string num2) {
        int l1=num1.size();
        int l2=num2.size();
        
        vector<int> res(l1+l2,0);//res[0] is lowest bit
        int carry=0;
        for(int i=0; i<l1; i++){
            int carry=0;
            for(int j=0; j<l2; j++){
                int digit=(num1[l1-1-i]-'0')*(num2[l2-1-j]-'0')+carry+res[i+j];
                carry=digit/10;
                res[i+j]=digit%10;
            }
            if(carry!=0){
                res[i+l2]=carry;
            }
        }
        
        //remove leading 0
        int start=l1+l2-1;
        while(start>=0 && res[start]==0){
            start--;
        }
        if(start<0){
            return "0";
        }
        
        string ret="";
        for(int i=start; i>=0; i--){
            ret=ret+char(res[i]+'0');
        }
        
        return ret;
    }
};