class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        
        for(int i=0; i<n; i++){
            while(nums[i]!=i+1){
                //nums[i] == nums[nums[i] - 1] handles the case where there are two identical values  like A = [1, 1]
                if(nums[i]<=0 || nums[i]>n || nums[i]==nums[nums[i]-1]){
                    break;
                }
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        
        for(int i=0; i<n; i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }
        return n+1;
        
    }
    
};