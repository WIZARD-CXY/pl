class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        int can=nums[0];
        int count=1;
        
        for(int i=1; i<nums.size(); i++){
            if(nums[i]!=can){
                count--;
            }else{
                count++;
            }
            
            if(count==0){
                can=nums[i];
                count=1;
            }
            
        }
        
        return can;
    }
};

