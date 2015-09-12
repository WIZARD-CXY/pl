/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    /**
     * @param n an integer
     * @param m an integer
     * @param operators an array of point
     * @return an integer array
     */
    vector<int> numIslands2(int n, int m, vector<Point>& operators) {
        // Write your code here
        vector<int> res;
        
        if(n==0 || m==0){
            return res;
        }
        
        int dx[]={0,1,0,-1};
        int dy[]={-1,0,1,0};
        
        unordered_map<int,int> father;
        unordered_map<int,bool> vis;
        
        
        for(auto op : operators){
            //set itself as father
            father[op.x*m+op.y]=op.x*m+op.y;
        }
        
        int cnt=0;
        for(auto op : operators){
            int opidx=op.x*m+op.y;
            int opfather=find(father,opidx);
            
            //new group
            if(opfather==opidx){
                cnt++;
            }
            vis[opidx]=true;
            
            // search 4 dirs
            for(int i=0; i<4; i++){
                int newx=op.x+dx[i];
                int newy=op.y+dy[i];
                
                if(newx<0 || newx>=n || newy<0 || newy>=m){
                    continue;
                }
                
                int newid=newx*m+newy;
                
                if(vis.find(newid)!=vis.end()){
                    //previous visited neighbour found;
                    int newfather=find(father,newid);
                    //find again in case the opidx father is changed during the update 
                    int opfather=find(father,opidx);
                    
                    if(newfather!=opfather){
                        cnt--;
                        //merge neighbour into one group
                        father[min(newfather,opfather)]=max(newfather,opfather);
                    }
                }
            }
            res.push_back(cnt);
        }
        
        return res;
    }
    int find(unordered_map<int,int> &father, int x){
        return father[x]==x?x:father[x]=find(father,father[x]);
    }
};
