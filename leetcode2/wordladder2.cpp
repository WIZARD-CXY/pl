class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &wordList) {
        vector<string> path;
        vector<vector<string> > res;
        
        unordered_map<string, vector<string> > father;
        unordered_set<string> vis;
        unordered_set<string> current;
        unordered_set<string> next;
        current.insert(start);
        bool found=false;
        
        while(!current.empty() && !found){
            //mark all the current level element as visited
            for(auto x : current){
                vis.insert(x);
            }
            
            for(auto x : current){
                for(int i=0; i<x.size(); i++){
                    string tmp=x;
                    for(char c='a'; c<='z'; c++){
                        if(tmp[i]==c){
                            continue;
                        }
                        
                        tmp[i]=c;
                        
                        if(tmp==end){
                            found=true;
                        }
                        
                        if(vis.find(tmp)==vis.end() && wordList.find(tmp)!=wordList.end()){
                            //univisited and in the wordlist
                            next.insert(tmp);
                            father[tmp].push_back(x);
                        }
                    }
                }
            }
            //move to the next level
            current=next;
            next.clear();
        }
        if(found){
          helper(res,path,father,start,end);  
        }
        
        return res;
    }
    void helper(vector<vector<string> > &res, vector<string> &path, unordered_map<string,vector<string> > &father,string start, string end){
        path.push_back(end);
        
        if(start==end){
            vector<string> tmppath=path;
            reverse(tmppath.begin(),tmppath.end());
            res.push_back(tmppath);
            path.pop_back();
            return;
        }
        
        for(auto f : father[end]){
            helper(res,path,father,start,f);
        }
        path.pop_back();
    }
};