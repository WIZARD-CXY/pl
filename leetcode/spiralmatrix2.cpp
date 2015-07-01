class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> >res;
        res.assign(n,vector<int>(n,0));
        int lx=0,ly=0;
        int rx=n-1,ry=n-1;
        
        //indicate full round number
        int e=n/2;
        int count=1;
        
        while(e--){
            for(int i=ly; i<=ry; i++){
                res[lx][i]=count++;
            }
            for(int i=lx+1; i<=rx; i++){
                res[i][ry]=count++;
            }
            for(int i=ry-1; i>=ly; i--){
                res[rx][i]=count++;
            }
            for(int i=rx-1; i>=lx+1; i--){
                res[i][lx]=count++;
            }
            lx++;
            ly++;
            rx--;
            ry--;
        }
        if(lx==rx){
            res[lx][ly]=count;
        }
        return res;
    }
};