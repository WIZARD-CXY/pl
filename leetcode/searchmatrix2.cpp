class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m=matrix.size();
        if(m==0){
            return false;
        }
        int n=matrix[0].size();
        if(n==0){
            return false;
        }
        
        int col=n-1;
        int row=0;
        
        while(col>=0 && row<m){
            if(matrix[row][col]==target){
                return true;
            }else if(matrix[row][col]<target){
                row++;
            }else{
                col--;
            }
        }
        
        return false;
        
    }
};