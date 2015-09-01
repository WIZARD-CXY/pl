class Solution {
public:
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
        
        vector<int> height(n,0);
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]=='0'){
                    height[j]=0;
                }else{
                    height[j]=height[j]+1;
                }
            }
            int maxarea=maxhistogram(height);
            res=max(res,maxarea);
        }
        return res;
    }
    
    int maxhistogram(vector<int> &height){
        stack<int> ss;
        int i=0;
        int res=0;
        
        // push_back a dummy element to recycle
        height.push_back(0);
        
        while(i<height.size()){
            if(ss.empty() || height[i]>=height[ss.top()]){
                ss.push(i++);
            }else{
                int idx=ss.top();
                ss.pop();
                
                int area=height[idx]*(ss.empty()?i:i-1-ss.top());
                res=max(area,res);
            }
        }
        return res;
    }
};