class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int flag=1;
        
        for(int i=1; i<nums.size(); i++){
            if(flag){
                //nums[i]>nums[i-1] is correct order
                if(nums[i]<nums[i-1]){
                    swap(nums[i],nums[i-1]);
                }
                flag=!flag;
            }else{
                //nums[i]<nums[i-1] is correct order
                if(nums[i]>nums[i-1]){
                    swap(nums[i],nums[i-1]);
                }
                flag=!flag;
            }
        }
    }
};