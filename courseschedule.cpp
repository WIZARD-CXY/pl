class Solution {
public:
    vector<vector<int> > G;
    vector<int> vis;
    vector<int> res;
    int t;
    
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
        res[--t]=u;
        
        return true;
    }
    bool topo(int n){
        t=n;
        for(int u=0; u<n; u++){
            if(!vis[u]){
                if(!dfs(u)){
                    return false;
                }
            }
        }
        return true;
    }
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        G.assign(numCourses,vector<int>(0));
        vis.assign(numCourses,0);
        res.assign(numCourses,0);
        
        int m=prerequisites.size();
        for(int i=0; i<m; i++){
            G[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        
        if(topo(numCourses)){
            return res;
        }
        return vector<int>();
    }
};