class Solution {
public:
    int jump(vector<int>& nums) {
        int curReach=0; //currently reach pos
        int curMax=0; //currently the max we can reach
        int res=0;
        
        for(int i=0; i<nums.size(); i++){
            
            if(curReach<i){
                // need to take a jump
                curReach=curMax;
                res++;
            }
            
            if(curMax<i+nums[i]){
                curMax=i+nums[i];
            }
        }
        
        return res;
    }
};