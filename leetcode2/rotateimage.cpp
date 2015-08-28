class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        
        // swap across anti-dialog
        // swap(matrix[i][j],matrix[n-1-j][n-1-i]);
        // swap across dialog
        // swap(matrix[i][j],matrix[j][i])
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n-1-i; j++){
                swap(matrix[i][j],matrix[n-1-j][n-1-i]);
            }
        }
        
        for(int i=0; i<n/2; i++){
            for(int j=0; j<n; j++){
                swap(matrix[i][j],matrix[n-1-i][j]);
            }
        }
    }
};