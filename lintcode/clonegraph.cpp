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
    /**
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // write your code here
        if(node==NULL){
            return NULL;
        }
        
        //use a map to store the new node and old node
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mm;
        
        // use dfs to create node
        return helper(mm,node);
    }
    
     UndirectedGraphNode* helper(unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> &mm,UndirectedGraphNode* node){
         
         if(mm.find(node)==mm.end()){
            // not exist the new node
            UndirectedGraphNode* newnode = new UndirectedGraphNode(node->label);
            mm[node]=newnode;
            
            //travese its neighbour and update neighbour
            for(auto neighbor : node->neighbors){
                newnode->neighbors.push_back(helper(mm,neighbor));
            }
            return newnode;
         }else{
             // just return 
             return mm[node];
         }
     }
};
