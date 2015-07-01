/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
#define UNode UndirectedGraphNode
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL){
            return NULL;
        }
        
        UNode* nnode = new UNode(node->label);
        // key is original node, value is new node.
        unordered_map<UNode*, UNode*> mm;
        mm[node]=nnode;
        
        dfs(mm,node);
        
        return nnode;
        
    }
    
    void dfs(unordered_map<UNode*, UNode*> &mm, UNode* cur){
        for(int i=0; i != cur->neighbors.size(); i++){
            UNode *now = cur->neighbors[i];
            if((mm.find(now))!=mm.end()){
                //neighbor pre-exist in the map just update the neighbors
                mm[cur]->neighbors.push_back(mm[now]);
            }else{
                //cloned neighbor not existed before, just create a new node and dfs on it
                UNode *nnow = new UNode(now->label);
                mm[now]=nnow;
                mm[cur]->neighbors.push_back(nnow);
                dfs(mm,now);
            }
        }
    }
};