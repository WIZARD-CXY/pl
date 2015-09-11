class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int can1=nums[0];
        int count=1;
        
        for(int i=1; i<nums.size(); i++){
            if(nums[i]==can1){
                count++;
            }else{
                count--;
                if(count==0){
                    can1=nums[i];
                    count=1;
                }
            }
        }
        
        return can1;
    }
};