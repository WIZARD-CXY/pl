class Solution {
public:  
    vector<vector<int> > G;
    vector<int> vis;
    
    bool dfs(int u){
        vis[u]=-1;
        
        for(int i=0; i<G[u].size(); i++){
            int v=G[u][i];
            
            if(vis[v]<0){
                return false;
            }else if(!vis[v] && !dfs(v)){
                return false;
            }
        }
        vis[u]=1;
        
        return true;
    }
    bool topo(int n, vector<int>& vis){
        for(int u=0; u<n; u++){
            if(!vis[u]){
                if(!dfs(u)){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        // transfer the prerequisites to adjacent list graph representation
        int n=prerequisites.size();
        vis.assign(numCourses,0);
        
        G.assign(numCourses,vector<int>(0));
        
        for(int i=0; i<n; i++){
            G[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        
        return topo(numCourses,vis);
    }
};