/**
 * Definition for Undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param nodes a array of Undirected graph node
     * @return a connected set of a Undirected graph
     */
    vector<vector<int>> connectedSet(vector<UndirectedGraphNode*>& nodes) {
        // Write your code here
        vector<vector<int> > res;
        
        int n=nodes.size();
        
        unordered_map<UndirectedGraphNode*,bool> vis;
        
        for(int i=0; i<n; i++){
            vis[nodes[i]]=0;
        }

        vector<int> tmp;
        for(int i=0; i<n; i++){
            if(!vis[nodes[i]]){
                tmp.clear();
                dfs(nodes[i],tmp,vis);
                sort(tmp.begin(),tmp.end());
                res.push_back(tmp);
            }
        }
        return res;
    }
    
    void dfs(UndirectedGraphNode* node, vector<int> &tmp,unordered_map<UndirectedGraphNode*,bool> &vis){
        vis[node]=true;
        tmp.push_back(node->label);
        
        for(auto neigh : node->neighbors){
            if(!vis[neigh]){
                dfs(neigh,tmp,vis);
            }
        }
    }
};
