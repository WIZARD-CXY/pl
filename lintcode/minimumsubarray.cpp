class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
    int minSubArray(vector<int> nums) {
        // write your code here
        if(nums.size()==0){
            return 0;
        }
        
        int res=nums[0];
        int sum=nums[0];
        for(int i=1; i<nums.size(); i++){
            if(sum>0){
                sum=nums[i];
            }else{
                sum+=nums[i];
            }
            
            res=min(res,sum);
        }
        
        return res;
    }
};