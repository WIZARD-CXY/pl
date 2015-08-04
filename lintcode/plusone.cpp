class Solution {
public:
    /**
     * @param digits a number represented as an array of digits
     * @return the result
     */
    vector<int> plusOne(vector<int>& digits) {
        // Write your code here
        int n=digits.size();
        
        vector<int> res;
        int carry=1;
        
        for(int i=n-1; i>=0 || carry !=0 ; i--){
            int sum;
            if(i>=0){
                sum=digits[i]+carry;
                res.insert(res.begin(),sum%10);
                carry=sum/10;
            }else{
                res.insert(res.begin(),carry);
                carry=0;
            }
        }
        
        return res;
    }
};
