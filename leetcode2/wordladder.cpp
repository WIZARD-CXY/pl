class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        //use bfs to travesal
        queue<string> qq;
        qq.push(beginWord);
       
        int level=1;
        wordDict.erase(beginWord);
        int count=1;
        
        while(!qq.empty()){
            string x=qq.front();
            qq.pop();
            count--;
            
            //try to search
            
            for(int i=0; i<x.size(); i++){
                string tmp=x;
                for(char c='a'; c<='z'; c++){
                    if(tmp[i]==c){
                        continue;
                    }
                    
                    if(tmp==endWord){
                        return level+1;
                    }
                    
                    tmp[i]=c;
                    if(wordDict.find(tmp)!=wordDict.end()){
                        wordDict.erase(tmp);
                        qq.push(tmp);
                    }
                }
            }
            if(count==0){
                count=qq.size();
                level++;
            }
        }
        return 0;
    }
};