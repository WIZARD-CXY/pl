class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int r=0,g=0,b=0;
        
        for(int i=0; i<costs.size(); i++){
            int rr=r,gg=g,bb=b;
            
            // update current house color
            // r, g, b means the current i-th house colored with red or
            // green or blue plus the (i-1)-th house minimum cost with different color
            r=costs[i][0]+min(gg,bb);
            g=costs[i][1]+min(rr,bb);
            b=costs[i][2]+min(rr,gg);
        }
        
        return min(r,min(g,b));
    }
};