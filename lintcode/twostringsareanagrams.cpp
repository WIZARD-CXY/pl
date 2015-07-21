class Solution {
public:
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    bool anagram(string s, string t) {
        // write your code here
        if(s.size()!=t.size()){
            return false;
        }
        int count[256]={0};
        
        for(int i=0; i<s.size(); i++){
            int idx=(unsigned char)s[i];
            count[idx]++;
        }
        
        for(int i=0; i<t.size(); i++){
            int idx=(unsigned char)t[i];
            if((--count[idx])<0){
                return false;
            }
        }
        return true;
    }
};
