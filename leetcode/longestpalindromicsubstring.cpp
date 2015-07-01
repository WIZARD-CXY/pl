class Solution {
public:
    string longestPalindrome(string s) {
        int len=s.size();
        int x,y; //record the max substring head and tail
        
        int max=0;
        
        for(int i=0; i<len; i++){
            // odd length like ABA
            for(int j=0; i-j>=0 && i+j<len; j++){
                if(s[i-j]!=s[i+j]){
                    break;
                }
                
                if(2*j+1>max){
                    max=2*j+1;
                    x=i-j;
                    y=i+j;
                }
            }
            
            // even length like ABBA
            for(int j=0; i-j>=0 && i+j+1<len; j++){
                if(s[i-j]!=s[i+j+1]){
                    break;
                }
                
                if(2*j+2>max){
                    max=2*j+2;
                    x=i-j;
                    y=i+j+1;
                }
            }
            
        }
        
        return s.substr(x,y-x+1);
        
    }
};