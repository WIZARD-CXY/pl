class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's previous permuation
     */
    vector<int> previousPermuation(vector<int> &nums) {
        // write your code here
        int i,j;
        if(nums.size()==0){
            return nums;
        }
        
        // find from tail to head the fisrt increasing element 
        for(i=nums.size()-2; i>=0; i--){
            if(nums[i]>nums[i+1]){
                break;
            }
        }
        
        if(i>=0){
            // find the first element that is larger than nums[i] which is nums[j]
            j=i+1;
            
            for(;j<=nums.size()-1; j++){
                if(nums[j]>=nums[i]){
                    break;
                }
            }
            
            // then swap the nums[i] and nums[j-1] which is the largest element which is smaller than nums[i]
            swap(nums[i],nums[j-1]);
            // then reverse
            reverse(nums.begin()+i+1,nums.end());
            return nums;
            
        }
        // else all in increasing order from head to tail 
        reverse(nums.begin(),nums.end());
        return nums;
    }
};
