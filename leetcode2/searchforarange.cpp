class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lower=lower_bound(nums,target);
        int upper=upper_bound(nums,target);
        
        if(nums[lower]!=target){
            return {-1,-1};
        }else{
            return {lower,upper-1};
        }
    }
    // returns the first index of element which larger or equal to target in nums array
    int lower_bound(vector<int> &nums, int target){
        int l=0;
        int r=nums.size();
        
        while(l<r){
            int mid=l+((r-l)>>1);
            
            // notice >=
            if(nums[mid]>=target){
                r=mid;
            }else{
                l=mid+1; 
            }
        }
        
        return l;
    }
    //returns the first index of element which is larger than target in nums
    int upper_bound(vector<int> &nums, int target){
        int l=0;
        int r=nums.size();
        
        while(l<r){
            int mid=l+((r-l)>>1);
            // notice > 
            if(nums[mid]>target){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        
        return l;
    }
};