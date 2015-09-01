class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        int mid=l;
        
        while(nums[l]>nums[r]){
            //if rotated
            if(r-l==1){
                mid=r;
                break;
            }
             
            int mid=l+((r-l)>>1);
            
            if(nums[mid]>=nums[l]){
                l=mid;
            }else if(nums[mid]<=nums[r]){
                r=mid;
            }
        }
        
        return nums[mid];
        
    }
};