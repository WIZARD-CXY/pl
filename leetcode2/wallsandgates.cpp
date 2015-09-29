class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m=rooms.size();
        
        if(m==0){
            return;
        }
        
        int n=rooms[0].size();
        
        if(n==0){
            return;
        }
        
        queue<pair<int,int> > qq;
        //first insert all the gate pos into the qq
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(rooms[i][j]==0){
                    qq.push(make_pair(i,j));
                }
            }
        }
        
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        
        while(!qq.empty()){
            int x=qq.front().first;
            int y=qq.front().second;
            qq.pop();
            
            for(int i=0; i<4; i++){
                int newx=x+dx[i];
                int newy=y+dy[i];
                // cross out of the grid or has smaller distance already just continue
                if(newx<0 || newy<0 || newx>=m || newy >=n || rooms[newx][newy]<rooms[x][y]+1){
                    continue;
                }
                
                rooms[newx][newy]=rooms[x][y]+1;
                qq.push(make_pair(newx,newy));
            }
        }
    }
};