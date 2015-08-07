class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: return nothing (void), do not return anything, modify nums in-place instead
     */
    void nextPermutation(vector<int> &nums) {
        // write your code here
        int i,k;
        
        // find the first decreasing element from right
        // 1432
        // i=0
        for(i=nums.size()-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                break;
            }
        }
        
        if(i<0){
            //already last permutation
            reverse(nums.begin(),nums.end());
            return;
        }
        //then find the first element from right larger than nums[i]
        // k=3
        for(k=nums.size()-1; k>i; k--){
            if(nums[k]>nums[i]){
                break;
            }
        }
        // 2 4 3 1
        swap(nums[i],nums[k]);
        // 2 1 3 4
        reverse(nums.begin()+i+1,nums.end());
    }
};
