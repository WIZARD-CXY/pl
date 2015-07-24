class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        
        int curReach=0;// the largest distance that has been reached
        int curMax=0; // the largest distance that can reach by taking ret+1 step
        int res=0; // the current jump number
        
        for(int i=0; i<n; i++){
            if(curMax<i){
                return -1;// can't get the last index return -1
            }
            if(curReach<i){
                // if the current farthest reach can not get i, need take another jump to get to curMax
                res++;
                curReach=curMax;
            }
            // every time try to update the largest jump distance
            curMax=max(curMax,i+nums[i]);
        }
        
        return res;
        
    }
};