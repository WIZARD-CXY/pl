class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if(start.empty() || end.empty()){
            return 0;
        }
        if(start==end){
            return 0;
        }
        
        queue<string> path;
        path.push(start);
        int level=1;
        int count=1;
        
        while(!path.empty() && dict.size()>0){
            string temp = path.front();
            path.pop();
            count--;
            for(int i=0; i<temp.size(); i++){
                for(int j='a'; j<='z'; j++){
                   if(temp[i]==j){
                       continue;
                   }
                   
                   temp[i]=j;
                   if(temp==end){
                       return level+1;
                   }
                   if(dict.find(temp)!=dict.end()){
                       path.push(temp);
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