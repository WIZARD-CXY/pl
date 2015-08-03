class Solution {
public:
    /**
     * @param s A string
     * @return Whether the string is a valid palindrome
     */
    bool isPalindrome(string& s) {
        // Write your code here
        int n=s.size();
        if(n==0){
            return true;
        }
        
        int start=0,end=n-1;
        
        while(start<end){
            if(!isvalid(s[start])){
                start++;
                continue;
            }
            if(!isvalid(s[end])){
                end--;
                continue;
            }
            
            if(s[end]==s[start] || abs(s[end]-s[start])==abs('A'-'a')){
                start++;
                end--;
                continue;
            }
            return false;
        }
        return true;
    }
    
    bool isvalid(char c){
        if((c>='a' && c<= 'z') || (c>='A' && c <= 'Z') || (c>='0' && c<='9')){
            return true;
        }
        return false;
    }
};
