class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int wordSize=words[0].size();
        int wordCount=words.size();
        
        if(s.size()<wordCount*wordSize){
            return res;
        }
        
        unordered_map<string,int> count;
        
        for(int i=0;i<words.size(); i++){
            count[words[i]]++;
        }
        
        unordered_map<string,int> has;
        
        for(int i=0; i<=s.size()-wordCount*wordSize; i++){
            has.clear();
            
            int j;
            for(j=0; j<wordCount; j++){
                string temp=s.substr(i+j*wordSize,wordSize);
                
                if(count.find(temp)!=count.end()){
                    has[temp]++;
                    if(has[temp]>count[temp]){
                        break;
                    }
                }else{
                    break;
                }
            }
            
            if(j==wordCount){
                res.push_back(i);
            }
            
        }
        return res;
    }
};