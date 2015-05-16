class Solution {
public:
    int trap(vector<int>& height) {
        
        int n=height.size();
        
        if(n<2){
            return 0;
        }
        
        int result=0;
        
        int leftMax[n]={0};
        int rightMax[n]={0};
        
        for(int i=1; i<n; i++){
            leftMax[i]=max(leftMax[i-1],height[i-1]);
            rightMax[n-1-i]=max(rightMax[n-i],height[n-i]);
        }
        
        for(int i=0; i<n; i++){
            int sum=min(leftMax[i],rightMax[i]);
            if(sum>height[i]){
                result+=sum-height[i];
            }
        }
        return result;
        
    }
};