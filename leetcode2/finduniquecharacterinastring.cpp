class Solution {
public:
    int firstUniqChar(string s) {
        int mm[26]={0};
        
        for(int i=0; i<s.size(); i++){
            mm[s[i]-'a']++;
        }
        
        for(int i=0; i<s.size(); i++){
            if(mm[s[i]-'a']==1){
                return i;
            }
        }
        return -1;
    }
};