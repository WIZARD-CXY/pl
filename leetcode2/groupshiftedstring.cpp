class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string> > res;
        
        unordered_map<string,vector<string> > mm;
        
        for(auto str :strings){
            string sig=getSig(str);
            mm[sig].push_back(str);
        }
        
        for(auto kv : mm){
            sort(kv.second.begin(),kv.second.end());
            res.push_back(kv.second);
        }
        
        return res;
    }
    
    string getSig(string str){
        //get string signature
        //like 'az' is z, 'ach' is 'cf'
        string t;
        for(int i=1; i<str.size(); i++){
            int diff=str[i]-str[i-1];
            if(diff<0){
                diff+=26;
            }
            t+=('a'+diff);
        }
        
        return t;
    }
};