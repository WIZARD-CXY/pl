class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: a integer
     */
    int trapRainWater(vector<int> &heights) {
        // write your code here
        int n=heights.size();
        //lh[i] records the max height left of heights[i]
        vector<int> lh(n,0);
        //rh[i] records the max hegiht right of height[i];
        vector<int> rh(n,0);
        
        for(int i=1; i<n; i++){
            // current lh[i] = height[i-1] or lh[i-1]
            lh[i]=max(heights[i-1],lh[i-1]);
            rh[n-i-1]=max(heights[n-i],rh[n-i]);
        }
        
        int res=0;
        for(int i=0; i<n; i++){
            int h=min(lh[i],rh[i]);
            if(heights[i]<h){
                res+=(h-heights[i]);
            }
        }
        return res;
    }
};
