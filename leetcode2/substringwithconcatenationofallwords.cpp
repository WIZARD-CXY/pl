class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int wordslen=words.size();
        int wordlen=words[0].size();
        int slen=s.size();
        unordered_map<string,int> need;
        unordered_map<string,int> has;
        
        for(auto word : words){
            need[word]++;
        }
        
        vector<int> res;
        
        for(int i=0; i<=slen-wordslen*wordlen; i++){
            int j;
            has.clear();
            
            for(j=0; j<wordslen; j++){
                
                string item=s.substr(i+j*wordlen,wordlen);
                auto it=need.find(item);
                
                if(it==need.end()){
                    // not exist in words
                    break;
                }else{
                    if(has[item]<need[item]){
                        has[item]++;
                    }else{
                        //already has more
                        break;
                    }
                }
            }
            if(j==wordslen){
                res.push_back(i);
            }
        }
        
        return res;
    }
};