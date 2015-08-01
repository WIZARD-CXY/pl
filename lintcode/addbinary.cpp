class Solution {
public:
    /**
     * @param a a number
     * @param b a number
     * @return the result
     */
    string addBinary(string& a, string& b) {
        // Write your code here
        int m=a.size();
        int n=b.size();
        
        int carry=0;
        int i=m-1,j=n-1;
        
        string res;
        int x,y;
        while(i>=0 || j>=0 || carry!=0){
            if(i<0){
                x=0;
            }else{
                x=a[i--]-'0';
            }
            if(j<0){
                y=0;
            }else{
                y=b[j--]-'0';
            }
            
            int sum=x+y+carry;
            
            res=char(sum%2+'0')+res;
            carry=sum/2;
        }
        
        return res;
    }
};
