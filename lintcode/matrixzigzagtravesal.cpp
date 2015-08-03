class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @return: a vector of integers
     */
    vector<int> printZMatrix(vector<vector<int> > &matrix) {
        // write your code here
        vector<int> res;
        int m=matrix.size();
        if(m==0){
            return res;
        }
        
        int n=matrix[0].size();
        if(n==0){
            return res;
        }
        
        int count=m*n;
        int col=0,row=0;
        res.push_back(matrix[0][0]);
        
        while(--count){
            //go right up
            while(row-1>=0 && col+1<n){
                res.push_back(matrix[--row][++col]);
            }
            //first go right or go down
            if(col+1<n){
                res.push_back(matrix[row][++col]);
            }else if(row+1<m){
                res.push_back(matrix[++row][col]);
            }
            
            //then go left-down
            while(row+1<m && col-1>=0){
                res.push_back(matrix[++row][--col]);
            }
            
            //then go right or go down
            if(row+1<m){
                //go down
                res.push_back(matrix[++row][col]);
            }else if(col+1<n){
                //go right
                res.push_back(matrix[row][++col]);
            }
        }
        return res;
    }
};
