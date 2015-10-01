class Solution {
public:
    //adjacent list graph
    unordered_map<char, unordered_set<char> > g;
    vector<int> vis;
    int t;
    
    string alienOrder(vector<string>& words) {
        if(words.size()==1){
            return words[0];
        }
        
        g=buildGraph(words);
        
        string res=topo();
        cout<<res.size()<<endl;
        return res; 
        
    }
    
    string topo(){
        int n=g.size();
        string res=string(n,'a');
        t=n;
        vis.assign(256,0);
        
        for(auto kv : g){
            if(!vis[kv.first]){
                if(!dfs(kv.first,res)){
                    return "";
                }
            }
        }
        
        return res;
    }
    
    bool dfs(char u, string &res){
        vis[u]=-1;
        
        for(auto v: g[u]){
            if(vis[v]==-1){
                return false;
            }else if (!vis[v] && !dfs(v,res)){
                return false;
            }
        }
        
        vis[u]=1;
        res[--t]=u;
        
        return true;
    }
    
    unordered_map<char,unordered_set<char> > buildGraph(vector<string> &words){
        int n=words.size();
        unordered_map<char,unordered_set<char> > g;
        
        for(int i=1; i<n; i++){
            int l1=words[i-1].size();
            int l2=words[i].size();
            int lmax=max(l1,l2);
            
            bool flag=false;
            
            for(int j=0; j<lmax; j++){
                if(j<l1 && g.find(words[i-1][j])==g.end()){
                    g[words[i-1][j]]=unordered_set<char>();
                }
                if(j<l2 && g.find(words[i][j])==g.end()){
                    g[words[i][j]]=unordered_set<char>();
                }
                
                if(j<l1 && j<l2 && words[i-1][j]!=words[i][j] && !flag){
                    //if a different is found we can stop
                    g[words[i-1][j]].insert(words[i][j]);
                    flag=true;
                }
            }
        }
        
        return g;
    }
};