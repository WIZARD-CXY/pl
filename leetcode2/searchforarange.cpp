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
    
    int upper_bound(vector<int> &nums, int target){
        int l=0;
        int r=nums.size();
        
        while(l<r){
            int mid=l+((r-l)>>1);
            
            if(nums[mid]>target){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        
        return l;
    }
};