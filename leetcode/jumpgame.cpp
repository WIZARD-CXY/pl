class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==0 || nums.size()==1){
            return true;
        }
        
        int maxstep=nums[0];
        
        for(int i=1; i<nums.size(); i++){
            if(maxstep==0){
                return false;
            }
            maxstep--;
            
            maxstep=max(maxstep,nums[i]);
            
            if(i+maxstep+1>=nums.size()){
                return true;
            }
        }
        
    }
};