class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        vector<vector<string> > res;
        
        unordered_map<string,vector<string> > mm;
        
        for(auto str : strs){
            string signature=str;
            sort(signature.begin(),signature.end());
            
            mm[signature].push_back(str);
            
        }
        
        for(auto it : mm){
            vector<string> svec=it.second;
            sort(svec.begin(),svec.end());
            res.push_back(svec);
        }
        
        return res;
        
    }
};