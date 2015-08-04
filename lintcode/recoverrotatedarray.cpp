class Solution {
public:
    void recoverRotatedSortedArray(vector<int> &nums) {
        // write your code here
        int n=nums.size();
        if(n==0 || n==1){
            return;
        }
        
        //find the rotation point
        int i;
        for(i=1; i<nums.size(); i++){
            if(nums[i]<nums[i-1]){
                break;
            }
        }
        if(i==nums.size()){
            return;
        }
        
        // i is the rotation point
        reverse(nums.begin(),nums.begin()+i);
        reverse(nums.begin()+i,nums.end());
        reverse(nums.begin(),nums.end());
    }
};
