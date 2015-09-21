class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        auto it1=words.end();
        auto it2=words.end();
        int res=words.size();
        
        for(auto it=words.begin(); it!=words.end(); it++){
            if(*it==word1){
                it1=it;
            }else if(*it==word2){
                it2=it;
            }
            
            if(it1!=words.end() && it2!=words.end() && res>abs(it1-it2)){
                res=abs(it1-it2);
            }
        }
        
        return res;
    }
};