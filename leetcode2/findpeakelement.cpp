class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0;
        int r=nums.size();
        
        while(l<r){
            int mid=l+((r-l)>>1);
            
            if(mid+1<nums.size() && nums[mid] < nums[mid+1]){
                //peak is in the right side
                l=mid+1;
            }else if (mid-1>=0 && nums[mid]<nums[mid-1]){
                r=mid;
            }else{
                return mid;
            }
        }
    }
};