class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string> > res;
        if(start == end){
            return res;
        }
        
        unordered_set<string> current,next;
        unordered_set<string> flag;
        unordered_map<string,vector<string> > father;
        
        current.insert(start);
        
        bool found=false;
        
        while(!current.empty() && !found){
            //expand
            for(const auto &x: current){
                flag.insert(x);
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
                        
                        if(dict.find(temp)!=dict.end() && flag.find(temp)==flag.end()){
                            next.insert(temp);
                            father[temp].push_back(x);
                        }
                    }
                }
            }
            
            current=next;
        }
        
        if(found){
            vector<string> c;
            dfs(res,father,c,start,end);
        }
        
        return res;
    }
    
    void dfs(vector<vector<string> > &res, const unordered_map<string,vector<string> > &father, vector<string> &c,string &start,string &now){
        c.push_back(now);
        
        if(now==start){
            reverse(c.begin(),c.end());
            res.push_back(c);
            c.pop_back();
            return;
        }
        
        auto que = father.find(now)->second;
        
        for(auto x : que){
            dfs(res,father,c,start,x);
        }
        
        c.pop_back();
    }
};