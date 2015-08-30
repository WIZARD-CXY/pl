class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int start=0;
        int end=0;
        int sum=0;
        int res=INT_MAX;
        
        if(nums.size()==0){
            return 0;
        }
        while(end<nums.size()){
            sum+=nums[end];
            
            if(sum>=s){
                //try to make it smaller
                while(sum-nums[start]>=s){
                    sum-=nums[start];
                    start++;
                }
                res=min(end-start+1,res);
            }
            end++;
        }
        
        if(res==INT_MAX){
            return 0;
        }
        return res;
        
    }
};