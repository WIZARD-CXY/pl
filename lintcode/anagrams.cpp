class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        // write your code here
        unordered_map<string, vector<string> > mm;
        vector<string> res;
        for(auto s: strs){
            string temp=s;
            sort(temp.begin(),temp.end());
            //temp is anagrams's signature
            mm[temp].push_back(s);
        }
        
        for(auto iter=mm.begin(); iter!=mm.end(); iter++){
            if(iter->second.size()>1){
                res.insert(res.end(),iter->second.begin(),iter->second.end());
            }
        }
        
        return res;
    }
};

