/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
     
    unordered_map<DirectedGraphNode*,int> vis;
    int t;
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        // write your code here
        vector<DirectedGraphNode*> res;
        
        topo(res,graph);
        
        return res;
    }
    
    bool topo(vector<DirectedGraphNode*> &res, vector<DirectedGraphNode*> &graph){
        int n=graph.size();
        
        res.assign(n,NULL);
        //initialize vis as all nodes is unvisited
        for(int i=0; i<n; i++){
            vis[graph[i]]=0;
        }
        
        t=n;
        
        for(auto u : graph){
            if(!vis[u]){
                if(!dfs(res, u)){
                    return false;
                }
            }
        }
        return true;
    }
    bool dfs(vector<DirectedGraphNode*> &res, DirectedGraphNode *u){
        vis[u]=-1;//in visiting
        
        //dfs its neighbour
        
        for(auto v : u->neighbors){
            if(vis[v]<0){
                return false;
            }else if(!vis[v] && !dfs(res,v)){
                return false;
            }
        }
        vis[u]=1;
        res[--t]=u;
        
        return true;
    }
};
