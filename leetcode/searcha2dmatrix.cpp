class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0){
            return false;
        }
        int row=matrix.size();
        int col=matrix[0].size();
        
        int l=0,r=row*col;
        
        while(l<r){
            int mid=(l+r)/2;
            
            int rowIdx=mid/col;
            int colIdx=mid%col;
            if(matrix[rowIdx][colIdx]==target){
                return true;
            }else if(matrix[rowIdx][colIdx]>target){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return false;
        
    }
};