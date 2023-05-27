class Solution {
public:
    string longestPalindrome(string s) {
        int maxlen=0;
        int start=0;
        int end=0;
        
        for(int i=0;i<s.size(); i++){
            //for odd len string
            for(int j=0; i-j>=0 &&i+j <s.size(); j++){
                if(s[i-j]!=s[i+j]){
                    break;
                }
                
                if(2*j+1>maxlen){
                    maxlen=2*j+1;
                    start=i-j;
                    end=i+j;
                }
            }
            
            //for even len string
            for(int j=0; i-j>=0 &&i+j+1 <s.size(); j++){
                if(s[i-j]!=s[i+j+1]){
                    break;
                }
                
                if(2*j+2>maxlen){
                    maxlen=2*j+2;
                    start=i-j;
                    end=i+j+1;
                }
            }
        }
        
        return s.substr(start,end-start+1);
    }
};