class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.size()!=s2.size()){
            return false;
        }
        
        if(s1==s2){
            return true;
        }
        
        int a[26]={0};
        
        for(int i=0; i<s1.size();i++){
            a[s1[i]-'a']++;
        }
        
        for(int i=0; i<s2.size(); i++){
            a[s2[i]-'a']--;
        }k
        
        for(int i=0; i<26; i++){
            if(a[i]!=0){
                return false;
            }
        }
        
        for(int i=1; i<s1.size();i++){
            bool res = isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i),s2.substr(i));
            res = res || (isScramble(s1.substr(0,i),s2.substr(s2.size()-i)) && isScramble(s1.substr(i),s2.substr(0,s2.size()-i)));
            
            if (res==true){
                return res;
            }
        }
        
        return false;
    }
};