class Solution {
public:
    /**
     * @param matrix an integer matrix
     * @return the coordinate of the left-up and right-down number
     */
    vector<vector<int>> submatrixSum(vector<vector<int>>& matrix) {
        // Write your code here
        
        vector<vector<int> > res(2,vector<int>(2));
        int m=matrix.size();
        if(m==0){
            return res;
        }
        int n=matrix[0].size();
        
        if(n==0){
            return res;
        }
        
        //sum[i][j] records [0][0] to [i-1][j-1] submatrix sum 1 started
        vector<vector<int> > sum(m+1,vector<int>(n+1,0));
        
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                sum[i][j]=matrix[i-1][j-1]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
            }
        }
        //
        for(int l=0; l<m; l++){
            for(int h=l+1; h<=m; h++){
                unordered_map<int,int> mm;
                for(int c=0; c<=n; c++){
                    //use diff to record the [l][0] to [h-1][c-1] sum 
                    int diff=sum[h][c]-sum[l][c];
                    
                    if(mm.find(diff)==mm.end()){
                        mm[diff]=c;
                    }else{
                        //found the answer
                        res[0][0]=l;res[0][1]=mm[diff];
                        res[1][0]=h-1;res[1][1]=c-1;
                        return res;
                    }
                }
            }
        }
        
        return res;     
    }
};
