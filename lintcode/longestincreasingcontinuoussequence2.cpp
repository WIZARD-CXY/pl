class Solution {
public:
    /**
     * @param A an integer matrix
     * @return  an integer
     */
    int res=0;
    int longestIncreasingContinuousSubsequenceII(vector<vector<int>>& A) {
        // Write your code here
        
        int m=A.size();
        if(m==0){
            return 0;
        }
        
        int n=A[0].size();
        if(n==0){
            return 0;
        }
        
        //d[i][j] means the max increasing continuous subsequence len starting 
        // from A[i][j];
        vector<vector<int> > d(m,vector<int>(n,0));
        
        for(int i=0;i<m; i++){
            for(int j=0; j<n; j++){
                if(d[i][j]==0){
                    //start from A[i][j]
                    dfs(A,i,j,INT_MIN,d);
                }
            }
        }
        
        return res;
    }
    
    int dfs(vector<vector<int> > &A, int x, int y, int pre, vector<vector<int> > &d){
        if(x<0 || x>=A.size() || y<0 || y>=A[0].size() || A[x][y]<=pre){
            return 0;
        }
        
        if(d[x][y]>0){
            return d[x][y];
        }
        
        vector<pair<int,int> > dirs={{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        for(auto dir : dirs){
            d[x][y]=max(d[x][y],1+dfs(A,x+dir.first,y+dir.second,A[x][y],d));
        }
        res=max(res,d[x][y]);
        
        return d[x][y];
    }
};
