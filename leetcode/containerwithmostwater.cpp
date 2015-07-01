class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        
        int l=0, r=n-1;
        int res=INT_MIN;
        while(l<r){
            int area=min(height[l],height[r])*(r-l);
            res=max(res,area);
            
            if(height[l]<height[r]){
                int k=l;
                
                while(k<r && height[k]<=height[l]){
                    k++;
                }
                l=k;
            }else{
                int k=r;
                
                while(k>l && height[k]<=height[r]){
                    k--;
                }
                
                r=k;
            }
            
        }
        return res;
    }
};