class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res=INT_MIN, f=0;
        
        for(int i=0; i<nums.size(); i++){
            f=max(f+nums[i],nums[i]);
            res=max(res,f);
        }
        return res;
    }
};