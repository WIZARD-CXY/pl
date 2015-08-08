class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: an integer
     */
    int maxArea(vector<int> &heights) {
        // write your code here
        int n=heights.size();
        
        if(n==0){
            return 0;
        }
        
        int l=0;
        int r=n-1;
        int res=INT_MIN;
        
        while(l<r){
            int area=min(heights[l],heights[r])*(r-l);
            
            res=max(res,area);
            
            if(heights[l]<heights[r]){
                //l is　shortcomings
                // try to find a higher height
                
                int k=l+1;
                
                while(k<r && heights[k]<heights[l]){
                    k++;
                }
                l=k;
            }else{
                // r is shortcomings
                // try to find a higher height
                
                int k=r-1;
                while(k>l && heights[k]<heights[r]){
                    k--;
                }
                r=k;
            }
        }
        
        return res;
    }
};
