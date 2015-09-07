class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return a list of lists of string
      */
    vector<string> path;
    vector<vector<string> > res;
    
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // write your code
        
        // one string may have many father
        unordered_map<string,vector<string> > father;
        unordered_set<string> current,next;
        unordered_set<string> vis;
        
        current.insert(start);
        //indicate found or not
        bool found=false;
        
        while(!current.empty() && !found){
            //mark all string in current as visited
            for(auto x: current){
                vis.insert(x);
            }
            
            // traversal the current level and try to add next level
            for(auto cur : current){
                for(int i=0; i<cur.size(); i++){
                    //try to change every letter of cur
                    string tmp=cur;
                    
                    for(char c='a'; c<='z'; c++){
                        if(tmp[i]==c){
                            continue;
                        }
                        
                        tmp[i]=c;
                        
                        if(tmp==end){
                            found=true;
                        }
                        //not visited before and in the dict put it into next level
                        if(vis.find(tmp)==vis.end() && dict.find(tmp)!=dict.end()){
                            // find it in a dict
                            father[tmp].push_back(cur);
                            next.insert(tmp);
                        }
                    }
                }
            }
            
            current=next;
            next.clear();
        }
        
        if(found){
            //use dfs to find res
            dfs(father,start,end);
        }
        
        return res;
    }
    //find a path from end to start
    void dfs(unordered_map<string,vector<string> > &father, string start, string end){
        
        path.push_back(end);
        if(start==end){
            vector<string> tmp=path;
            reverse(tmp.begin(),tmp.end());
            res.push_back(tmp);
            
            //reverse(res.back().begin(),res.back().end());
            path.pop_back();
            return;
        }
        
        auto fathers = father.find(end)->second;

        for(auto fa : fathers){
            dfs(father,start,fa);
        }
        path.pop_back();
    }
};
