class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<string> path;
        path.push(start);
        int level=1;
        int count=1;//indicate the level-th level unvisited variable count
        
        while(!path.empty() && dict.size()>0){
            string cur = path.front();
            path.pop();
            count--;
            for(int i=0; i<cur.size(); i++){
                string temp=cur;
                // traversal all 26 case 'a' to 'z' except temp[i]
                for(char j='a'; j<='z'; j++){
                   if(temp[i]==j){
                       continue;
                   }
                   
                   temp[i]=j;
                   if(temp==end){
                       return level+1;
                   }
                   if(dict.find(temp)!=dict.end()){
                       path.push(temp);
                       //kind like prune
                       dict.erase(temp);
                   }
                }    
            }
            if(count==0){
                count=path.size();
                level++;
            }
        }
        return 0;
    }
};  