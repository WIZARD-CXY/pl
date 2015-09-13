class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mm1;
        unordered_map<char,char> mm2;
        
        for(int i=0; i<s.size(); i++){
            if(mm1.find(s[i])==mm1.end()){
                mm1[s[i]]=t[i];
            }else{
                if(mm1[s[i]]!=t[i]){
                    return false;
                }
            }
            
            if(mm2.find(t[i])==mm2.end()){
                mm2[t[i]]=s[i];
            }else{
                if(mm2[t[i]]!=s[i]){
                    return false;
                }
            }
        }
        
        return true;
    }
};