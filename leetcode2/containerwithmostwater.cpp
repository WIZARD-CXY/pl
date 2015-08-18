class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        
        int res=0;
        while(l<r){
            int area=min(height[l],height[r])*(r-l);
            res=max(res,area);
            
            if(height[l]<height[r]){
                //height[l] is shorter, looking for a higher index k
                int k=l;
                while(k<r && height[k]<=height[l]){
                    k++;
                }
                l=k;
            }else{
                //height[r] is shorter, looking for a higher index k
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