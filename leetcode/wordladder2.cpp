class Solution {
public:
    vector<vector<string> > res;
    vector<string> temp_path;

    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        
        if(start == end){
            return res;
        }
        
        unordered_set<string> current,next;
        unordered_set<string> unvisited;
        unordered_map<string,vector<string> > father;
        
        current.insert(start);

        bool found=false;
        
        while(!current.empty() && !found){

            for(auto &x: current){
                unvisited.insert(x);
            }
            
            for(auto x :current){
                for(int i=0; i<x.size(); i++){
                    string temp=x;

                    for(char j='a'; j<='z'; j++){
                        if(temp[i]==j){
                            continue;
                        }
                        
                        temp[i]=j;
                        
                        if(temp==end){
                            found=true;
                        }
                
                        if(dict.find(temp)!=dict.end() && unvisited.find(temp)==unvisited.end()){
                            next.insert(temp);
                            father[temp].push_back(x);
                        }
                    }
                }
            }
            
            current=next;
            next.clear();
        }
        
        if(found){
            dfs(father,start,end);
        }
        
        return res;
    }
    
    void dfs(const unordered_map<string,vector<string> > &father, string start, string now){
        temp_path.push_back(now);
        
        if(now==start){
            res.push_back(temp_path);
            // do not get temp_path dirty, reverse it in the res.back
            reverse(res.back().begin(),res.back().end());
            temp_path.pop_back();
            return;
        }
        
        auto que = father.find(now)->second;
        
        for(auto x : que){
            dfs(father,start,x);
        }
        
        temp_path.pop_back();
    }
};