class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number occurs more than 1/3.
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        //given two candidates
        int can1=nums[0];
        int can2=0;
        int count1=1;
        int count2=0;
        
        for(int i=1; i<nums.size(); i++){
            if(nums[i]==can1){
                count1++;
            }else if (nums[i] ==can2){
                count2++;
            }else{
                if(count1==0){
                    count1=1;
                    can1=nums[i];
                }else if(count2==0){
                    count2=1;
                    can2=nums[i];
                }else{
                    count1--;
                    count2--;
                }
                
            }
        }
        
        if(count1 >0 && count2>0){
            count1=count2=0;
            for(int i=0; i<nums.size(); i++){
                if(nums[i]==can1){
                    count1++;
                }else if(nums[i]==can2){
                    count2++;
                }
            }
            return count1>count2?can1:can2;
        }else{
            return count1==0?can2:can1;
            
        }
        
    }
};