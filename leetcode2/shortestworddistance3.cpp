class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int res=words.size();
        
        if(word1==word2){
            //same word
            int pre=-1;
            for(int i=0; i<words.size(); i++){
                
                if(words[i]==word1){
                    if(pre!=-1){
                        res=min(res,i-pre);
                    }
                    
                    pre=i;
                }
            }
        }else {
            //word1 != word2
            int idx1=-1,idx2=-1;
            
            for(int i=0; i<words.size(); i++){
                if(words[i]==word1){
                    idx1=i;
                }else if(words[i]==word2){
                    idx2=i;
                }
                
                if(idx1!=-1 && idx2!=-1){
                    res=min(res,abs(idx1-idx2));
                }
            }
        }
        
        return res;
    }
};