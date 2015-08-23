class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int idx=1;
        int last=nums[0];
        
        for(int i=1; i<nums.size(); i++){
            if(nums[i]!=last){
                nums[idx++]=nums[i];
                last=nums[i];
            }
        }
        return idx;
    }
};