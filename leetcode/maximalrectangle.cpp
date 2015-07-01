class Solution {
public:
    // same as the largest histogram
    int maxHistogram(vector<int> height){
        int res=0;
        
        height.push_back(0);
        stack<int> ss;
        
        int i=0;
        while(i<height.size()){
            if(ss.empty() || height[i]>=height[ss.top()]){
                ss.push(i++);
            }else{
                int t=ss.top();
                ss.pop();
                res=max(res,height[t]*(ss.empty()?i:i-ss.top()-1));
            }
        }
        return res;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int res=0;
        
        int m=matrix.size();
        if(m==0){
            return 0;
        }
        
        int n=matrix[0].size();
        if(n==0){
            return 0;
        }
        
        // height record every row's histogram
        vector<int> height;
        height.assign(n,0);
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                height[j]=matrix[i][j]=='0'?0:height[j]+1;
            }
            res=max(res,maxHistogram(height));
        }
        
        return res;
    }
};