class Solution {
public:
    string multiply(string num1, string num2) {
        int l1=num1.size();
        int l2=num2.size();
        
        vector<int> v(l1+l2,0);
        
        for(int i=0; i<l1; i++){
            int carry=0;
            
            for(int j=0; j<l2; j++){
                // calculate from rightmost to left
                int sum=(num1[l1-i-1]-'0')*(num2[l2-j-1]-'0')+carry+v[i+j];
                carry=sum/10;
                v[i+j]=sum%10;
            }
            
            if(carry>0){
                // fill the left with carry
                v[i+l2]=carry;
            }
        }
        
        int start=l1+l2-1;
        
        while(start>=0 && v[start]==0){
            start--;
        }
        
        if(start==-1){
            return "0";
        }
        
        string res="";
        for(int i=start; i>=0; i--){
            res=res+char(v[i]+'0');
        }
        
        return res;
    }
};