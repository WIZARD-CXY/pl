class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cur0=0,cur1=0,cur2=nums.size()-1;
        
        while(cur1<=cur2){
            if(nums[cur1]==0){
                swap(nums[cur1],nums[cur0]);
                cur1++;
                cur0++;
            }else if(nums[cur1]==1){
                cur1++;
            }else{
                swap(nums[cur1],nums[cur2]);
                cur2--;
            }
        }
        
    }
};