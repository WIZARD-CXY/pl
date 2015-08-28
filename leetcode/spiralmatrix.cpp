class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m=matrix.size();
        
        if(m==0){
            return res;
        }
        
        int n=matrix[0].size();
        if(n==0){
            return res;
        }
        
        int lx=0,ly=0;
        int rx=m-1,ry=n-1;
        
        // 
        //------> y
        //| 1 2 3
        //| 4 5 6
        //| 7 8 9 
        //x
        // e indicate the full round count, a full round is 1 2 3 6 9 8 7 4
        
        int e=min(m,n)/2;
        
        while(e--){
            //traverse from left to right
            for(int i=ly; i<=ry; i++){
                res.push_back(matrix[lx][i]);// 1 2 3
            }
            //traverse from up to down
            for(int i=lx+1; i<=rx; i++){
                res.push_back(matrix[i][ry]);//6 9
            }
            //traverse from right to left
            for(int i=ry-1; i>=ly; i--){
                res.push_back(matrix[rx][i]);// 8 7
            }
            //travese from down to up
            for(int i=rx-1;i>=lx+1; i--){ // 4
                res.push_back(matrix[i][ly]);
            }
            // move the up left conner right-down and down right corner left up 
            lx++;
            ly++;
            rx--;
            ry--;
        }
        
        // push back the heart part of matrix like 5
        if(lx==rx){
            for(int i=ly; i<=ry; i++){
                res.push_back(matrix[lx][i]);
            }
        }else if(ly==ry){
            for(int i=lx; i<=rx; i++){
                res.push_back(matrix[i][ly]);
            }
        }
        
        return res;
        
    }
};