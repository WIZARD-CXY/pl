class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(),s.end());
        
        int l=0;
        int r=0;
        
        while(r<s.size()){
            while(r<s.size() && s[r]!=' '){
                r++;
            }
            reverse(s.begin()+l,s.begin()+r);
            l=++r;
        }
    }
};