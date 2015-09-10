
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size();
        
        while(l<r){
            int mid = (l+r)/2;
            
            if(nums[mid]==target){
                return true;
            }
            //only compare with left element
            if(nums[l]<nums[mid]){
                if(nums[l]<=target && target<nums[mid]){
                    r=mid;
                }else{
                    l=mid+1;
                }
            }else if(nums[mid]<nums[l]){
                if(nums[mid]<target && target <= nums[r-1]){
                    l=mid+1;
                }else{
                    r=mid;
                }
            }else{
                l++;
            }
        }
        return false;
        
    }
};