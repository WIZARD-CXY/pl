class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > res(n,vector<int>(n,0));
        
        int round=n/2;
        int count=1;
        int lx=0,ly=0;
        int rx=n-1,ry=n-1;
        
        while(round--){
            //first left to right
            for(int i=ly; i<=ry; i++){
                res[lx][i]=count++;
            }
            
            //then up to down
            for(int i=lx+1; i<=rx; i++){
                res[i][ry]=count++;
            }
            
            // then right to left
            for(int i=ry-1; i>=ly; i--){
                res[rx][i]=count++;
            }
            
            // then down to up
            for(int i=rx-1;i>=lx+1; i--){
                res[i][ly]=count++;
            }
            lx++;
            ly++;
            rx--;
            ry--;
        }
        
        if(lx==rx){
            //when n is odd, set the heart of matrix
            res[lx][ly]=count;
        }
        
        return res;
    }
};