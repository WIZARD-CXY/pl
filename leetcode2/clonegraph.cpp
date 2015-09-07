/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node==NULL){
            return NULL;
        }
        //use dfs to clone
        unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> mm;
        //map old node to new node
        
        UndirectedGraphNode* newnode = new UndirectedGraphNode(node->label);
        mm[node]=newnode;
        
        helper(mm,node);
        
        return newnode;
    }
    
    void helper(unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> &mm,UndirectedGraphNode* node){
        for(auto n: node->neighbors){
            if(mm.find(n)==mm.end()){
               UndirectedGraphNode* newnode= new UndirectedGraphNode(n->label);
               mm[n]=newnode;
               mm[node]->neighbors.push_back(newnode);
               helper(mm,n);
            }else{
                mm[node]->neighbors.push_back(mm[n]);
            }
        }
    }
};