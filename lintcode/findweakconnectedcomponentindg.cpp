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
     * @param nodes a array of directed graph node
     * @return a connected set of a directed graph
     */
     
    // union find
    int find(unordered_map<int,int> &father, int x){
        if(x==father[x]){
            return x;
        }else{
            int y=x;
            while(y!=father[y]){
                y=father[y];
            }
            father[x]=y;
            return y;
        }
    }
    
    vector<vector<int>> connectedSet2(vector<DirectedGraphNode*>& nodes) {
        // Write your code here
        unordered_map<int,int> father;
        
        for(auto n : nodes){
            //initial n's father is itself
            father[n->label]=n->label;
        }
        
        for(auto n : nodes){
            for(auto nn : n->neighbors){
                // fa is find every time because it may update below
                int fa=find(father,n->label);   
                int fb=find(father,nn->label);
                
                //merge the connected componet
                if(fa!=fb){
                    if(fa>fb){
                        //select the bigger as father
                        father[fb]=fa;
                    }else{
                        father[fa]=fb;
                    }
                }
            }
        }
        
        //find all the component
        unordered_map<int,vector<int> > comp;
        // key is the leader
        for(auto n : nodes){
            //not  comp[father[n->label]].push_back(n->label)
            //because use find can find the highest leader
            int fath=find(father,n->label);
            comp[fath].push_back(n->label);
        }
        
        vector<vector<int>> res;
        for(auto it=comp.begin(); it!=comp.end(); it++){
            sort(it->second.begin(),it->second.end());
            res.push_back(it->second);
        }
        return res;
    }
};
