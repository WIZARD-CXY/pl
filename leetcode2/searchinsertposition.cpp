class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums,target);
    }
    
    int lower_bound(vector<int> &nums, int target){
        int l=0;
        int r=nums.size();
        
        while(l<r){
            int mid=l+((r-l)>>1);
            
            if(nums[mid]>=target){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        
        return l;
    }
};