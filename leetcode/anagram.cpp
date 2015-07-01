class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > mm;
        
        for(int i=0; i<strs.size(); i++){
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            mm[temp].push_back(strs[i]);
        }
        
        vector<string>  res;
        for(auto iter=mm.begin(); iter!=mm.end(); iter++){
            if(iter->second.size()>1){
                res.insert(res.end(),iter->second.begin(),iter->second.end());
            }
        }
        
        return res;
    }
};