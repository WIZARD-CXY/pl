class Solution {
public:
    /**
     * @param s1 A string
     * @param s2 Another string
     * @return whether s2 is a scrambled string of s1
     */
    bool isScramble(string& s1, string& s2) {
        // Write your code here
        return isanagram(s1,s2);
    }
    
    bool isanagram(string &s1, string &s2){
        char count[256]={0};
        
        if(s1.size()!=s2.size()){
            return false;
        }
        for(int i=0; i<s1.size(); i++){
            int idx=(unsigned char)s1[i];
            
            count[idx]++;
        }
        
        for(int i=0; i<s2.size();i++){
            int idx=(unsigned char)s2[i];
            if(--(count[idx])<0){
                return false;
            }
        }
        
        return true;
    }
};
