class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int> > G(numCourses);
        for(int i=0; i<prerequisites.size(); i++){
            G[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        
        vector<int> vis(numCourses,0);
        return topo(G,vis);
    }
    
    bool topo(vector<vector<int> > &G, vector<int> &vis){
        for(int i=0; i<G.size(); i++){
            if(!vis[i]){
                if(!dfs(G,i,vis)){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool dfs(vector<vector<int> > &G, int u, vector<int> &vis){
        vis[u]=-1;
        
        for(int i=0; i<G[u].size(); i++){
            int v=G[u][i];
            if(vis[v]==-1){
                return false;
            }else if(vis[v]==0 && !dfs(G,v,vis)){
                return false;
            }
        }
        vis[u]=1;
        return true;
    }
};