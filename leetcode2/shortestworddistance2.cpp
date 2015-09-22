class WordDistance {
public:
    WordDistance(vector<string>& words) {
        for(int i=0; i<words.size(); i++){
            mm[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        vector<int> index1=mm[word1];
        vector<int> index2=mm[word2];
        
        int i=0,j=0;
        
        int res=INT_MAX;
        while(i<index1.size() && j<index2.size()){
            res=min(abs(index1[i]-index2[j]),res);
            
            if(index1[i]<index2[j]){
                i++;
            }else{
                j++;
            }
        }
        
        return res;
    }
    
    unordered_map<string, vector<int> > mm;
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");