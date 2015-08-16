class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        
        int count[256]={0};
        for(auto &c :s){
            int idx=(unsigned char)c;
            count[idx]++;
        }
        
        for(auto &c :t){
            int idx=(unsigned char)c;
            if((--count[idx])<0){
                return false;
            }
        }
        
        return true;
    }
};