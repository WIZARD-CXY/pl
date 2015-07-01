class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mm1,mm2;
        
        for(int i=0; i<s.size(); i++){
            if(mm1.find(t[i])==mm1.end()){
                mm1[t[i]]=s[i];
            }else{
                if(mm1.find(t[i])->second!=s[i]){
                    return false;
                }
            }
            
            if(mm2.find(s[i])==mm2.end()){
                mm2[s[i]]=t[i];
            }else{
                if(mm2.find(s[i])->second!=t[i]){
                    return false;
                }
            }
        }
        return true;
        
    }
};