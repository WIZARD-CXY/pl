class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        
        int base=1;
        while(x/base>=10){
            base*=10;
        }
        
        while(x){
            int leftdigit=x/base;
            int rightdigit=x%10;
            
            if(leftdigit != rightdigit){
                return false;
            }
            // remove the head and tail of x
            x=x%base/10;
            base/=100;
            
        }
        
        return true;
    }
};