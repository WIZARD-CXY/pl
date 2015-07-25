class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's next permuation
     */
    vector<int> nextPermutation(vector<int> &nums) {
        // write your code here
        int n=nums.size();
        int i,k;
        for(i=n-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                break;
            }
        }
        
        if(i<0){
            //all decreasing order need to reverse all
            reverse(nums.begin(),nums.end());
        }else{
            // find the first element that larger than nums[i] from tail
            for(k=n-1; k>=0; k--){
                if(nums[k]>nums[i]){
                    break;
                }
            }
            //swap them
            swap(nums[i],nums[k]);
            
            //then reverse
            reverse(nums.begin()+i+1,nums.end());
        }
        
        return nums;
    }
};
