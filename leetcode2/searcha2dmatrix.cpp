class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        
        if(m==0){
            return 0;
        }
        
        int n=matrix[0].size();
        if(n==0){
            return 0;
        }
        
        int l=0;
        int r=m*n;
        
        while(l<r){
            int mid=l+((r-l)>>1);
            int x=mid/n;
            int y=mid%n;
            
            if(matrix[x][y]==target){
                return true;
            }else if( matrix[x][y]>target){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        
        return 0;
        
    }
};