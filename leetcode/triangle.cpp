class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if(triangle.size()==0){
            return 0;
        }
        
        int layer=triangle.size();
        int largestSize=triangle[triangle.size()-1].size();
        
        //d[i][j] means the min value we can get start from triangle[i][j] 
        int d[layer][largestSize];

        // fill the bottom line
        for(int i=0; i<largestSize; i++){
            d[layer-1][i]=triangle[layer-1][i];
        }
        
        for(int i=layer-2; i>=0;i--){
            for(int j=0; j<triangle[i].size(); j++){
                d[i][j]=min(d[i+1][j],d[i+1][j+1])+triangle[i][j];
            }
        }
        
        return d[0][0];
    }
};