class Solution {
public:
    int partitionArray(vector<int> &nums, int k) {
        // write your code here
        int n=nums.size();
        //move k to the end of nums
        if(n==0){
            return 0;
        }
        
        int i=-1;
        for(int j=0; j<n; j++){
            if(nums[j]<k){
                swap(nums[++i],nums[j]);
            }
        }
        
        return ++i;
    }
};
