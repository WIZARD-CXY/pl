class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<bool> vis(n,0);
        vector<int> parent(n,0);
        
        for(int i=0; i<n; i++){
            parent[i]=i;
        }
        
        vector<vector<int> > G(n);
        //set up the graph
        for(auto e : edges){
            G[e.first].push_back(e.second);
            G[e.second].push_back(e.first);
        }
        
        stack<int> ss;
        
        vis[0]=1;
        ss.push(0);
        
        while(!ss.empty()){
            int tmp=ss.top();
            ss.pop();
            vis[tmp]=1;
            
            for(auto neighbour : G[tmp]){
                if(parent[tmp]!=neighbour){
                    if(vis[neighbour]==1){
                        //exist cycle
                        return false;
                    }
                    
                    ss.push(neighbour);
                    //set the parent of neighbour as tmp
                    parent[neighbour]=tmp;
                }
            }
        }
        
        //all visited
        for(int i=0; i<n; i++){
            if(!vis[i]){
                cout<<i<<endl;
                return false;
            }
        }
        
        return true;
    }

};