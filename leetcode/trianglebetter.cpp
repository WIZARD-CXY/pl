class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if(triangle.size()==0){
            return 0;
        }
        
        int layer=triangle.size();
        int largestSize=triangle[triangle.size()-1].size();
        
        int d[largestSize];
        for(int i=0; i<largestSize; i++){
            d[i]=triangle[layer-1][i];
        }
        
        for(int i=layer-2; i>=0;i--){
            for(int j=0; j<triangle[i].size(); j++){
                d[j]=min(d[j],d[j+1])+triangle[i][j];
            }
        }
        
        return d[0];
    }
};