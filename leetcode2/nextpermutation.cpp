class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i,k;
        for(i=nums.size()-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                break;
            }
        }
        
        if(i<0){
            // already the last permutation  all non-increasing order,just reverse
            reverse(nums.begin(),nums.end());
            return;
        }
        for(k=nums.size()-1; k>i; k--){
            if(nums[k]>nums[i]){
                break;
            }
        }
        
        swap(nums[i],nums[k]);
        reverse(nums.begin()+i+1,nums.end());
    }
};