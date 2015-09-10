class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        int mid=l;
        
        while(nums[l]>=nums[r]){
            if(nums[l]==nums[mid] && nums[mid]==nums[r]){
                return helper(nums,0,r);
            }
            
            if(r-l==1){
                return nums[r];
            }
            
            mid=l+((r-l)>>1);
            
            if(nums[mid]>=nums[l]){
                l=mid;
            }else if(nums[mid]<=nums[r]){
                r=mid;
            }
        }
        
        return nums[mid];
    }
    
    int helper(vector<int> &nums, int l, int r){
        int res=INT_MAX;
        
        for(int i=l; i<=r; i++){
            res=min(res,nums[i]);
        }
        
        return res;
    }
};