class Solution {
public:
    int lower_bound(vector<int> &nums, int target){
        int l=0,r=nums.size();
        
        while(l<r){
            int mid=(l+r)/2;
            if(nums[mid]>=target){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        
        return l;
    }
    
    int upper_bound(vector<int> &nums, int target){
        int l=0,r=nums.size();
        
        while(l<r){
            int mid = (l+r)/2;
            
            if(nums[mid]>target){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = lower_bound(nums,target);
        int up = upper_bound(nums,target);
        
        if(nums[low]!=target){
            return vector<int>{-1,-1};
        }
        return vector<int>{low,up-1};
        
    }
};