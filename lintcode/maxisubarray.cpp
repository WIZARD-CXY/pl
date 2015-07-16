class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        // write your code here
        int sum=nums[0];
        int res=sum;
        
        for(int i=1; i<nums.size(); i++){
            if(sum<0){
                //sum<0 just start a new sub array
                sum=nums[i];
            }else{
                // sum>0 can join the previous sub array
                sum+=nums[i];
            }
            res=max(res,sum);
        }
        
        return res;
    }
};

