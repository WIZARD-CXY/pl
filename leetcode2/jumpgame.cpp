class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int curmax=0; // record the current max reach index
        
        for(int i=0; i<n; i++){
            // update the current jump max to index
            if(i+nums[i]>curmax){
                curmax=i+nums[i];
            }
            
            //currentmax can jumpt to the last index
            if(curmax>=n-1){
                return true;
            }
            // can't move forward
            if(curmax==i){
                return false;
            }
        }
        
        return false;
    }
};