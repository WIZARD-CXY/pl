/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
 
// bfs solution
#define UNode UndirectedGraphNode
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL){
            return NULL;
        }
        
        UNode* nnode = new UNode(node->label);
        
        unordered_map<UNode*, UNode*> mm;
        mm[node]=nnode;
        
        queue<UNode*> qq;
        
        qq.push(node);
        
        while(!qq.empty()){
            UNode *cur=qq.front();
            qq.pop();
            
            for(int i=0; i<cur->neighbors.size(); i++){
                UNode *now = cur->neighbors[i];
                if(mm.find(now)!=mm.end()){
                    // a copy has already exist, just need to link to the neighbor
                    mm[cur]->neighbors.push_back(mm[now]);
                }else{
                    UNode *nnode = new UNode(now->label);
                    mm[now]=nnode;
                    mm[cur]->neighbors.push_back(nnode);
                    qq.push(now);
                }
            }
        }
        
        return nnode;
        
    }
};