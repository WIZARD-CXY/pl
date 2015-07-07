class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        int mid=l;
        
        while(nums[l]>=nums[r]){
            if(nums[l]==nums[r] && nums[l] == nums[mid]){
                return helper(nums,l,r);
            }
            if(r-l==1){
                mid=r;
                break;
            }
            
            mid=(l+r)>>1;
            if(nums[mid]>=nums[l]){
                l=mid;
            }else if(nums[mid]<=nums[r]){
                r=mid;
            }
        }
        
        return nums[mid];
        
    }
    int helper(vector<int> &nums, int l, int r){
        // linearly find the smallest element from l to r
        int res=INT_MAX;
        for(int i=l; i<=r; i++){
            res=min(res,nums[i]);
        }
        return res;
    }
};