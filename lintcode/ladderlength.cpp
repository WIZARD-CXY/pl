class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return an integer
      */
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // write your code here
        // use bfs search 
        queue<string> qq;
        qq.push(start);
        int count=1;
        int level=1;
        
        while(!qq.empty() && dict.size()!=0){
            string cur=qq.front();
            qq.pop();
            count--;
            
            for(int i=0; i<cur.size(); i++){
                string temp=cur;
                for(char c='a'; c<='z'; c++){
                    if(temp[i]==c){
                        continue;
                    }else{
                        temp[i]=c;
                        
                        if(temp==end){
                            return level+1;
                        }
                        
                        //find the temp in the dict
                        if(dict.find(temp)!=dict.end()){
                            qq.push(temp);
                            dict.erase(temp);
                        }
                    }
                }
            }
            
            if(count==0){
                level++;
                count=qq.size();
            }
        }
        
        return 0;
    }
};
