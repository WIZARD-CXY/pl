class Solution {
public:
    int t;
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        
        vector<vector<int> > G(numCourses);
        vector<int> res(numCourses);
        
        for(int i=0; i<prerequisites.size(); i++){
            G[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        
        vector<int> vis(numCourses,0);
        if(topo(G,vis,res)){
            return res;
        }else{
            return vector<int>();
        }
    }
    
    bool topo(vector<vector<int> > &G, vector<int> &vis, vector<int> &res){
        t=G.size();
        
        for(int i=0; i<G.size(); i++){
            if(!vis[i]){
                if(!dfs(G,vis,res,i)){
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool dfs(vector<vector<int> > &G, vector<int> &vis, vector<int> &res, int u){
        vis[u]=-1;
        
        for(int i=0; i<G[u].size(); i++){
            int v=G[u][i];
            
            if(vis[v]==-1){
                return false;
            }else if(!vis[v] && !dfs(G,vis,res,v)){
                return false;
            }
        }
        
        vis[u]=1;
        res[--t]=u;
        
        return true;
    }
};