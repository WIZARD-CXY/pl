class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size();
        
        while(l<r){
            int mid = l+((r-l)>>1);
            
            if(nums[mid]==target){
                return true;
            }
            
            if(nums[mid]>nums[l]){
                if(target>=nums[l] && target<nums[mid]){
                    r=mid;
                }else{
                    l=mid+1;
                }
            }else if(nums[mid]<nums[l]){
                if(target>nums[mid] && target<=nums[r-1]){
                    l=mid+1;
                }else{
                    r=mid;
                }
            }else{
                //nums[mid]==nums[l];
                l++;
            }
        }
        
        return false;
    }
};