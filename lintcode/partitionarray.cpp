class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        // write your code here
        int l=0;
        int r=nums.size()-1;
        
        while(l<r){
            // move l forward until it points to a even number
            while(l<r && (nums[l]&1)==1){
                l++;
            }
            //move r backward until it points to a odd number
            while(l<r && (nums[r]&1)!=1){
                r--;
            }
            //if we get l>=r means partion is over
            if(l<r){
                swap(nums[l],nums[r]);
            }
        }
    }
};
