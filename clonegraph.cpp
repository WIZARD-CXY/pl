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
    unordered_map<UNode*, UNode* >::iterator iter;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL){
            return NULL;
        }
        
        UNode* nnode = new UNode(node->label);
        // key is original node, value is new node.
        unordered_map<UNode*, UNode*> mm;
        mm[node]=nnode;
        
        dfs(mm,node,nnode);
        
        return nnode;
        
    }
    
    void dfs(unordered_map<UNode*, UNode*> &mm, UNode* node, UNode* nnode){
        for(int i=0; i != node->neighbors.size(); i++){
            UNode *now = node->neighbors[i];
            if((iter=mm.find(now))!=mm.end()){
                //neighbor pre-exist in the map just update the neighbors
                nnode->neighbors.push_back(iter->second);
            }else{
                //cloned neighbor not existed before, just create a new node and dfs on it
                UNode *nnow = new UNode(now->label);
                mm[now]=nnow;
                nnode->neighbors.push_back(nnow);
                dfs(mm,now,nnow);
            }
        }
    }
};