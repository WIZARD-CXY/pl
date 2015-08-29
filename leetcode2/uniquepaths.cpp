class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> d(n,1);
        // d[i][j] means the [0][0] to [i][j]'s unique path number
        
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                d[j]=d[j]+d[j-1];
            }
        }
        
        return d[n-1];
        
    }
};