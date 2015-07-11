class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        int m=matrix.size();
        if(m==0){
            return false;
        }
        int n=matrix[0].size();
        
        int l=0,r=m*n;
        while(l<r){
            int mid=(l+r)>>1;
            
            int x=mid/n;
            int y=mid%n;
            
            if(matrix[x][y]==target){
                return true;
            }else if(matrix[x][y]>target){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return false;
    }
};