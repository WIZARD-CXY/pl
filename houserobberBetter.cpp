class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        
        if(n==0){
            return 0;
        }
        if(n==1){
            return nums[0];
        }
        //no extra space required
        nums[1]=max(nums[1],nums[0]);
        
        for(int i=2; i<n; i++){
            nums[i]=max(nums[i-1],nums[i-2]+nums[i]);
        }
        
        return nums[n-1];
    }
};