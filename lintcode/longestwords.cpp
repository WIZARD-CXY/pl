class Solution {
public:
    /**
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        // write your code here
        vector<string> res;
        
        int n=dictionary.size();
        
        if(n==0){
            return res;
        }
        
        res.push_back(dictionary[0]);
        int maxlen=dictionary[0].size();
        
        for(int i=1; i<dictionary.size(); i++){
            if(dictionary[i].size() == maxlen){
                res.push_back(dictionary[i]);
            }else if(dictionary[i].size()> maxlen){
                maxlen=dictionary[i].size();
                res.clear();
                res.push_back(dictionary[i]);
            }
        }
        
        return res;
    }
};
