class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    void setZeroes(vector<vector<int> > &matrix) {
        // write your code here
        //use first row and first col as helper storage 
        // 
        int m=matrix.size();
        
        if(m==0){
            return;
        }
        int n=matrix[0].size();
        if(n==0){
            return;
        }
        
        // true means col and row have 0, will be set to 0
        bool colflag=false,rowflag=false;
        
        for(int i=0; i<m;i++){
            if(matrix[i][0]==0){
                colflag=true;
                break;
            }
        }
        
        for(int j=0; j<n; j++){
            if(matrix[0][j]==0){
                rowflag=true;
                break;
            }
        }
        
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[i][j]==0){
                    matrix[0][j]=matrix[i][0]=0;
                }
            }
        }
        
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[0][j]==0 || matrix[i][0]==0){
                    matrix[i][j]=0;
                }
            }
        }
        
        if(colflag){
            for(int i=0; i<m;i++){
               matrix[i][0]=0;
            }
        }
        
        if(rowflag){
            for(int j=0; j<n; j++){
               matrix[0][j]=0;
            }
        }
    }
};
