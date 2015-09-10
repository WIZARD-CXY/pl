class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxtmp=nums[0];
        int mintmp=nums[0];
        int res=nums[0];
        
        for(int i=1;i<nums.size(); i++){
            //first select tempmax and tempmin from `maxtmp*nums[i],mintmp*nums[i]`
            int tempmax=max(maxtmp*nums[i],mintmp*nums[i]);
            int tempmin=min(maxtmp*nums[i],mintmp*nums[i]);
            
            //update maxtmp and mintmp
            maxtmp=max(tempmax,nums[i]);
            mintmp=min(tempmin,nums[i]);
            res=max(res,maxtmp);
        }
        
        return res;
    }
};