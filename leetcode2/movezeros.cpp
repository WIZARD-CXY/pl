class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int i=-1;
        
        // like partition sort, just using 0 as pivot
        for(int j=0; j<n; j++){
            if(nums[j]!=0){
                swap(nums[++i],nums[j]);
            }
        }
    }
};